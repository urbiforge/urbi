cmake_minimum_required(VERSION 3.14)
project(Urbi CXX C)

set(ConfigFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfig.cmake)
set(ConfigPackageLocation share/cmake/urbi)
set(CPACK_PACKAGE_VENDOR "Emys Inc.")
set(CPACK_WIX_UI_REF "WixUI_Minimal")
set(CPACK_WIX_UPGRADE_GUID "ba25c4f0-b795-44a6-a29e-d785bfa66806")
set(CPACK_WIX_PROPERTY_ALLUSERS "1")
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_USE_DEBUG_RUNTIME OFF)

find_package(Boost COMPONENTS regex system filesystem thread chrono date_time signals REQUIRED)
find_package(Port REQUIRED)

include(CMakePackageConfigHelpers)
include(CPack)

#find python
find_program(_python_executable
    NAMES python2 python python.exe
    NO_CMAKE_FIND_ROOT_PATH)
  if (NOT _python_executable)
    qi_error("needs python executable in PATH")
  endif()


add_subdirectory(sdk-remote)

configure_file(include/urbi/kernel/config.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/urbi/kernel/config.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/sdk-remote/libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/sdk-remote/libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/urbi)

if (USE_BOOST_CORO)
  add_definitions(-DSCHED_USE_BOOST_CORO)
endif()

add_definitions(-DLIBPORT_LIBSFX="")
add_definitions(-DLIBPORT_LIBDIRNAME="lib")
add_definitions(-D_USE_MATH_DEFINES)
#add_definitions(/w)

# stack allocation seems to produce weird things on atom builds
if (I_AM_A_ROBOT)
  add_definitions(-DURBI_NO_VLENGTH_ARRAY)
endif ()


if (HAVE_CUSTOM_BISON)
#this needs to be done...
MESSAGE("Using bison")

#invoke flex on utoken.l
qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
  SRC src/parser/utoken.l
  COMMAND flex -+ -o${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/utoken.l
)

#fix flex output
qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
  SRC ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/fix-utoken.py ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc.raw ${CMAKE_CURRENT_BINARY_DIR}/src/parser/utoken.cc
)

# You need a bison patched by gostai, in the urbi-sdk/bison repository.
set(BISON_OPTS
  --defines --report=all -xml
)
set(BISON
  bison
)

qi_generate_src(
  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
  SRC src/parser/ugrammar.y
  COMMAND ${BISON} ${BISON_OPTS} ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/ugrammar.y -o  ${CMAKE_CURRENT_BINARY_DIR}/src/parser/ugrammar.cc
)

function(astgen target command)
 qi_generate_src(
   ${CMAKE_CURRENT_SOURCE_DIR}/${target}
  SRC src/ast/ast.yml
  COMMAND ${_python_executable} ${CMAKE_CURRENT_SOURCE_DIR}/dev/ast-${command}-gen ${CMAKE_CURRENT_SOURCE_DIR}/src/ast < ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/ast.yml
 )
endfunction()


astgen(src/ast/all.cc all)
astgen(src/ast/cloner.cc cloner)
astgen(src/ast/transformer.cc transformer)
astgen(src/ast/fwd.hh fwd)
astgen(src/ast/default-visitor.hh default-visitor)
astgen(src/ast/visitor.hh visitor)
astgen(src/ast/pretty-printer.cc pretty-printer)
astgen(src/ast/dot-printer.cc dot-printer)
astgen(src/ast/serializer.hh serializer)
astgen(src/ast/implicit.hh nodes)

set(GENERATED_SRC
  src/ast/visitor.hh
  src/ast/implicit.hh
  src/ast/all.cc
  src/ast/cloner.hxx
  src/ast/cloner.cc
  src/ast/dot-printer.cc
  src/ast/pretty-printer.cc
  src/ast/transformer.cc
  src/ast/default-visitor.hh
  src/ast/fwd.hh
)

else()
  MESSAGE("No bison specified, using pregenerated grammar and AST files.")

  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/pregenerated/ ${CMAKE_CURRENT_BINARY_DIR}/src/parser/)
  execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/pregenerated/ ${CMAKE_CURRENT_BINARY_DIR}/src/ast/)

  set(UOBJECT_GENERATED_SRC
    ${CMAKE_CURRENT_BINARY_DIR}/src/ast/merged.cc
  )

endif(HAVE_CUSTOM_BISON)

include(cmake/sources.cmake)

if (APPLE)
  # Workaround clang bug http://llvm.org/bugs/show_bug.cgi?id=14116
  set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O1")
endif()

if (NOT WIN32)
  list(APPEND UOBJECT_PLUGIN_SRC src/object/urbi/process.cc)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include/urbi/parser/)

# For ast/factory.cc
add_definitions(-D__SRCDIR__="")
add_definitions(-DBUILDING_URBI_SDK -DBUILDING_URBI_MODULE)

add_library(uobject SHARED ${UCO_SRC} ${UOBJECT_PLUGIN_SRC} ${UOBJECT_GENERATED_SRC})

target_link_libraries(uobject
    Port::port Port::sched Port::serialize Boost::regex Boost::signals Boost::filesystem Boost::date_time Boost::system Boost::thread)

set_target_properties(uobject
  PROPERTIES
    OUTPUT_NAME uobject
    INSTALL_NAME_DIR "@executable_path/../lib/gostai/engine"
    COMPILE_FLAGS -DBUILDING_URBI_SDK)

install(
    TARGETS
        uobject
    EXPORT
        UrbiTargets
    RUNTIME  DESTINATION
        lib/gostai/engine
    LIBRARY  DESTINATION
        lib/gostai/engine
    ARCHIVE  DESTINATION
        lib/gostai/engine
    INCLUDES DESTINATION
        include
)

add_subdirectory(share)
add_subdirectory(sdk-remote/src/uobjects)

export(
    EXPORT
        UrbiTargets
    FILE
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiTargets.cmake"
)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/UrbiConfig.cmake.in
    ${ConfigFile}
    INSTALL_DESTINATION ${ConfigPackageLocation}
)

install(
    EXPORT
        UrbiTargets
    FILE
        UrbiTargets.cmake
    DESTINATION
        ${ConfigPackageLocation}
)

install(
  FILES
    ${ConfigFile}
  DESTINATION
    ${ConfigPackageLocation}
)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/misc/images/cube.ico DESTINATION share/icons)
install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf DESTINATION ${CMAKE_INSTALL_PREFIX})




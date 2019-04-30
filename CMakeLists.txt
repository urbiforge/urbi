cmake_minimum_required(VERSION 3.14)
project(Urbi CXX C)

set(Urbi_VERSION 3.0.0)

set(CPACK_PACKAGE_VERSION ${Urbi_VERSION})
set(ConfigFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfig.cmake)
set(ConfigVersionFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfigVersion.cmake)
set(ConfigPackageLocation share/cmake/urbi)
set(CPACK_PACKAGE_VENDOR "Emys Inc.")
set(CPACK_WIX_UI_REF "WixUI_FeatureTree")
set(CPACK_WIX_UPGRADE_GUID "ba25c4f0-b795-44a6-a29e-d785bfa66806")
set(CPACK_WIX_PROPERTY_ALLUSERS "1")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_USE_DEBUG_RUNTIME OFF)

find_package(Boost COMPONENTS regex system filesystem thread chrono date_time signals REQUIRED)

if(DEFINED FIND_EXTERNAL_DEPENDENCIES)
  find_package(Port REQUIRED)
endif()

include(CMakePackageConfigHelpers)
include(CPackComponent)

add_subdirectory(external/libjpeg)
add_subdirectory(external/libport)

#find python
find_program(_python_executable
    NAMES python2 python python.exe
    NO_CMAKE_FIND_ROOT_PATH)
if (NOT _python_executable)
    message(ERROR "needs python executable in PATH")
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

# stack allocation seems to produce weird things on atom builds
if (I_AM_A_ROBOT)
  add_definitions(-DURBI_NO_VLENGTH_ARRAY)
endif ()


if (HAVE_CUSTOM_BISON)
  include(cmake/custom_bison.cmake)
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

# For ast/factory.cc
add_definitions(-D__SRCDIR__="")
add_definitions(-DBUILDING_URBI_SDK -DBUILDING_URBI_MODULE)

add_library(uobject SHARED ${UCO_SRC} ${UOBJECT_PLUGIN_SRC} ${UOBJECT_GENERATED_SRC})

target_include_directories(uobject
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/urbi/parser/>
        $<INSTALL_INTERFACE:include/urbi>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/include/urbi/parser/>
)

target_link_libraries(uobject
    Port::port Port::sched Port::serialize Boost::regex Boost::signals Boost::filesystem Boost::date_time Boost::system Boost::thread)

set_target_properties(uobject
    PROPERTIES
        OUTPUT_NAME uobject
        INSTALL_NAME_DIR "@executable_path/../lib/gostai/engine"
    COMPILE_FLAGS
        -DBUILDING_URBI_SDK
)

install(
    TARGETS
        uobject
    EXPORT
        UrbiTargets
    COMPONENT
        Runtime
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

install(
    DIRECTORY
        "${BOOSTROOT}/bin/"
    COMPONENT
        SDK
    DESTINATION
        bin
    FILES_MATCHING PATTERN
        "*.lib"
)

install(
    DIRECTORY
        "${BOOSTROOT}/bin/"
    COMPONENT
        Runtime
    DESTINATION
        bin
    FILES_MATCHING PATTERN "*.dll"
)

install(
    DIRECTORY
        "${BOOSTROOT}/include/"
    COMPONENT
        SDK
    DESTINATION
        include
)

write_basic_package_version_file(
        ${ConfigVersionFile}
    VERSION
        ${Urbi_VERSION}
    COMPATIBILITY
        AnyNewerVersion
)

export(
    EXPORT
        UrbiTargets
    FILE
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiTargets.cmake"
)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/UrbiConfig.cmake.in
    ${ConfigFile}
    INSTALL_DESTINATION
        ${ConfigPackageLocation}
)

install(
    EXPORT
        UrbiTargets
    FILE
        UrbiTargets.cmake
    COMPONENT
        SDK
    DESTINATION
        ${ConfigPackageLocation}
)

install(
    FILES
        ${ConfigVersionFile}
        ${ConfigFile}
    COMPONENT
        SDK
    DESTINATION
        ${ConfigPackageLocation}
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/misc/images/cube.ico
    COMPONENT
        Runtime
    DESTINATION
        share/icons
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf
    COMPONENT
        Runtime
    DESTINATION
        .
)

cpack_add_component(Runtime
    DISPLAY_NAME
        "Runtime components"
    REQUIRED
)

cpack_add_component(SDK
    DISPLAY_NAME
        "SDK components for developers"
    DISABLED
)

cpack_add_component(Others
    DISPLAY_NAME
        "Other components"
    HIDDEN
)

include(CPack)
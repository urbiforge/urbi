cmake_minimum_required(VERSION 3.22)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
  add_definitions(-DURBI_COMPILATION_MODE_DEBUG)
endif()


if(NOT STATIC_BUILD)
add_executable(urbi-launch
    src/bin/urbi-launch.cc
    src/liburbi/urbi-launch.cc
    src/liburbi/urbi-root.cc
    )
target_link_libraries(urbi-launch
  port sched serialize
)
set_target_properties(urbi-launch
PROPERTIES
  INSTALL_RPATH "$ORIGIN/../lib"
  )
if (NOT APPLE AND NOT WIN32)
  target_link_libraries(urbi-launch dl)
endif()

install(TARGETS urbi-launch)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libport/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../libport/include)

add_definitions(-DLIBPORT_LIBSFX="")
add_definitions(-DLIBPORT_LIBDIRNAME="lib")
add_definitions(-D_USE_MATH_DEFINES)

#In case we link to our libjpeg, mark it as static
add_definitions(-DJPEG_INTERNAL)

set(COMMON_SRC
src/libuco/details.cc
src/libuco/local.mk
src/libuco/uevent.cc
src/libuco/uobject-common.cc
src/libuco/uobject-hub-common.cc
src/libuco/uprop.cc
src/libuco/ustarter.cc
src/libuco/utable.cc
src/libuco/uvar-common.cc
src/libuco/version-check.cc
src/libuvalue/exit.cc
src/libuvalue/package-info.cc
src/libuvalue/ubinary.cc
src/libuvalue/uimage.cc
src/libuvalue/ulist.cc
src/libuvalue/usound.cc
src/libuvalue/uvalue-common.cc
)

set(URBI_SRC
src/liburbi/compatibility.hh
src/liburbi/compatibility.hxx
src/liburbi/kernel-version.cc
src/liburbi/uabstractclient.cc
src/liburbi/uclient.cc
src/liburbi/uconversion.cc
src/liburbi/umain.cc
src/liburbi/umessage.cc
src/liburbi/urbi-launch.cc
src/liburbi/urbi-root.cc
src/liburbi/usyncclient.cc
src/liburbi/utag.cc
)




# Look for system JPEG, use it if found, or use our internal version.
find_package(JPEG)
if(JPEG_FOUND)
  message("Using SYSTEM JPEG")
  set(JPEG_INCLUDE_DIRS ${JPEG_INCLUDE_DIR})
  set(JPEG_PACKAGE ${JPEG_LIBRARIES})
else()
  message("Using INTERNAL JPEG")
  add_definitions(-DJPEG_INTERNAL)
  set(JPEG_PACKAGE qijpeg)
  add_subdirectory(libjpeg)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libjpeg)
endif()

set(UOBJECT_REMOTE_SRC
  src/libuobject/main.cc
  src/libuobject/remote-ucontext-impl.hh
  src/libuobject/ucallbacks.cc
  src/libuobject/uobject.cc
  src/libuobject/utimer-callback.cc
  src/libuobject/uvar.cc
  src/libuco/urbi-main.cc
)

add_library(uobject-remote
  ${LIB_MODE}
  ${COMMON_SRC} ${UOBJECT_REMOTE_SRC} ${URBI_SRC}
)
target_link_libraries(uobject-remote
   port serialize ${JPEG_PACKAGE} Boost::regex Boost::date_time  Boost::system Boost::thread
)
set_target_properties(uobject-remote
  PROPERTIES
     OUTPUT_NAME uobject
     INSTALL_NAME_DIR "@executable_path/../lib/gostai/remote"
     COMPILE_FLAGS -DBUILDING_URBI_SDK
     INSTALL_RPATH "$ORIGIN/../..")

if (NOT APPLE AND NOT WIN32)
  target_link_libraries(uobject-remote dl)
endif()

install(TARGETS uobject-remote DESTINATION lib/gostai/remote)

#uobject-remote is instaled at a custom location.
#So we still need a liburbi for programs wanting to link with it
add_library(urbi
  ${LIB_MODE}
  ${COMMON_SRC} ${URBI_SRC}
)
target_link_libraries(urbi
  port serialize ${JPEG_PACKAGE} Boost::regex Boost::date_time  Boost::system Boost::thread
)
set_target_properties(urbi
  PROPERTIES
    COMPILE_FLAGS -DBUILDING_URBI_SDK)

if (NOT APPLE AND NOT WIN32)
  target_link_libraries(urbi dl)
endif()

install(TARGETS urbi)

if (NOT STATIC_BUILD)
add_subdirectory(src/examples)
endif()
add_subdirectory(include)

# Scripts

file(READ sdk/umake-common UMAKE_COMMON)
set(PACKAGE_BRAND "gostai")
set(exec_prefix "\${prefix}")
set(bindir "\${exec_prefix}/bin")
set(libdir "\${exec_prefix}/lib")
set(brandlibdir "\${libdir}/${PACKAGE_BRAND}")
set(libdirname "lib")
configure_file(sdk/urbi-launch-java.in ${CMAKE_CURRENT_BINARY_DIR}/sdk/urbi-launch-java @ONLY)
install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/sdk/urbi-launch-java DESTINATION bin)

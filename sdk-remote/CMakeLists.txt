cmake_minimum_required(VERSION 3.14)

if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(-DURBI_COMPILATION_MODE_DEBUG)
endif()

add_executable(urbi-launch 
    src/bin/urbi-launch.cc
    src/liburbi/urbi-launch.cc
    src/liburbi/urbi-root.cc
)

target_include_directories(urbi-launch
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

if (NOT APPLE AND NOT WIN32)
    set(URBI_LAUNCH_EXTRA_LINK_LIBS dl)
endif()

target_link_libraries(urbi-launch
    port::port port::sched port::serialize ${URBI_LAUNCH_EXTRA_LINK_LIBS})

install(
    TARGETS
        urbi-launch
    COMPONENT
        Runtime
    EXPORT
        UrbiTargets
    RUNTIME  DESTINATION
        bin
    LIBRARY  DESTINATION
        lib
    ARCHIVE  DESTINATION
        lib
    INCLUDES DESTINATION
        include
)

add_definitions(-DLIBPORT_LIBSFX="")
add_definitions(-DLIBPORT_LIBDIRNAME="lib")
add_definitions(-D_USE_MATH_DEFINES)

#In case we link to our libjpeg, mark it as static
add_definitions(-DJPEG_INTERNAL)

include(sources.cmake)

# Look for system JPEG, use it if found, or use our internal version.
find_package(JPEG QUIET)
if(JPEG_FOUND)
    message("Using SYSTEM JPEG")
    set(JPEG_INCLUDE_DIRS ${JPEG_INCLUDE_DIR})
    set(JPEG_PACKAGE JPEG)
else()
    message("Using INTERNAL JPEG")
    add_definitions(-DJPEG_INTERNAL)
    set(JPEG_PACKAGE qijpeg)

    if(DEFINED FIND_EXTERNAL_DEPENDENCIES)
        find_package(qijpeg REQUIRED)
    endif()
endif()

add_library(uobject-remote SHARED ${COMMON_SRC} ${UOBJECT_REMOTE_SRC} ${URBI_SRC})

if (NOT APPLE AND NOT WIN32)
    set(UOBJECT_REMOTE_EXTRA_LINK_LIBS DL)
endif()

target_include_directories(uobject-remote
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/urbi>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

target_link_libraries(uobject-remote
    port::port port::serialize ${JPEG_PACKAGE} ${UOBJECT_REMOTE_EXTRA_LINK_LIBS} Boost::regex Boost::date_time Boost::system Boost::thread)

set_target_properties(uobject-remote
    PROPERTIES
        OUTPUT_NAME uobject
        INSTALL_NAME_DIR "@executable_path/../lib/gostai/remote"
    COMPILE_FLAGS
        -DBUILDING_URBI_SDK
)

install(
    TARGETS
        uobject-remote
    EXPORT
        UrbiTargets
    COMPONENT
        SDK #???
    RUNTIME  DESTINATION
        lib/gostai/remote
    LIBRARY  DESTINATION
        lib/gostai/remote
    ARCHIVE  DESTINATION
        lib/gostai/remote
    INCLUDES DESTINATION
        include
)

#uobject-remote is instaled at a custom location.
#So we still need a liburbi for programs wanting to link with it
add_library(urbi SHARED ${COMMON_SRC} ${URBI_SRC})

target_include_directories(urbi
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include/urbi>
    PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

if (NOT APPLE AND NOT WIN32)
    set(URBI_EXTRA_LINK_LIBS dl)
endif()

target_link_libraries(urbi
    port::port port::serialize ${JPEG_PACKAGE} ${URBI_EXTRA_LINK_LIBS} Boost::regex Boost::date_time Boost::system Boost::thread)

set_target_properties(urbi
    PROPERTIES
        COMPILE_FLAGS -DBUILDING_URBI_SDK
)

install(
    TARGETS
        urbi
    COMPONENT
        Runtime
    EXPORT
        UrbiTargets
    RUNTIME  DESTINATION
        bin
    LIBRARY  DESTINATION
        lib
    ARCHIVE  DESTINATION
        lib
    INCLUDES DESTINATION
        include
)

add_subdirectory(src/examples)

install(
    FILES
        ${URBI_PUBLIC_HEADERS}
    COMPONENT
        SDK
    DESTINATION
        include/urbi
)

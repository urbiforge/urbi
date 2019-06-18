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

include(sources.cmake)

add_subdirectory(src/examples)

install(
    FILES
        ${URBI_PUBLIC_HEADERS}
    COMPONENT
        SDK
    DESTINATION
        include/urbi
)

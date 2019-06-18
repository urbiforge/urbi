add_library(urbi_headers INTERFACE)
target_include_directories(urbi_headers INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(urbi_headers INTERFACE port)

add_library(urbi_sources INTERFACE)
target_sources(urbi_sources INTERFACE
    src/kernel-version.cc
    src/uabstractclient.cc
    src/uclient.cc
    src/uconversion.cc
    src/umain.cc
    src/umessage.cc
    src/urbi-launch.cc
    src/urbi-root.cc
    src/usyncclient.cc
    src/utag.cc
    )

add_library(urbi_root INTERFACE)
target_sources(urbi_root INTERFACE src/urbi-root.cc)
target_link_libraries(urbi_root INTERFACE port)

add_library(urbi_launch INTERFACE)
target_sources(urbi_launch INTERFACE src/urbi-launch.cc)

add_library(urbi MODULE)
target_link_libraries(urbi PRIVATE urbi_sources urbi_headers uco uvalue port::port jpeg ${CMAKE_DL_LIBS})
target_compile_definitions(urbi PRIVATE BUILDING_URBI_SDK LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

install(
    TARGETS urbi_headers
    EXPORT UrbiTargets
    COMPONENT SDK
)

install(
    DIRECTORY include/urbi
    TYPE INCLUDE
    COMPONENT SDK
)
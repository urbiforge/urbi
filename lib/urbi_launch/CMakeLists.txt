add_executable(urbi-launch src/urbi-launch.cc)
target_link_libraries(urbi-launch PRIVATE port urbi_headers urbi_launch urbi_root ${CMAKE_DL_LIBS})
target_compile_definitions(urbi-launch PRIVATE LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

add_executable(urbi src/urbi.cc)
target_link_libraries(urbi PRIVATE urbi_headers urbi_launch urbi_root ${CMAKE_DL_LIBS})
target_compile_definitions(urbi PRIVATE LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

install(
    TARGETS urbi-launch urbi
    COMPONENT Runtime
)
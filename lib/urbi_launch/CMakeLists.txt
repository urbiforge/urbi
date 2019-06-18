add_executable(urbi-launch src/urbi-launch.cc)
target_link_libraries(urbi-launch PRIVATE port urbi_headers urbi_launch urbi_root ${CMAKE_DL_LIBS})
target_compile_definitions(urbi-launch PRIVATE LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

add_executable(urbi-interactive src/urbi.cc)
target_link_libraries(urbi-interactive PRIVATE urbi_headers urbi_launch urbi_root ${CMAKE_DL_LIBS})
target_compile_definitions(urbi-interactive PRIVATE LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

install(
    TARGETS urbi-launch urbi-interactive
    COMPONENT Runtime
)
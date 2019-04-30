add_executable(urbi-bandwidth
    urbi-bandwidth.cc)

target_link_libraries(urbi-bandwidth
    uobject-remote)

install(
    TARGETS
        urbi-bandwidth
    COMPONENT
        SDK
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
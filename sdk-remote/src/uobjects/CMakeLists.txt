function(uobject name path)
    # all uobjects can link with any of the uobjects
    # except lib-urbi which uses liburbi
    add_library(${name} MODULE ${ARGN})

    # Apple default to no unresolved,
    # but stores library path which will not do with uobject
    if (APPLE)
        set_target_properties(${name}
        PROPERTIES
            LINK_FLAGS "-undefined dynamic_lookup"
    )
    endif()

    target_link_libraries(${name} uobject-remote)

    set_target_properties( ${name}
    PROPERTIES
        PREFIX ""
    )

    install(
        TARGETS
            ${name}
        COMPONENT
            Runtime
        EXPORT
            UrbiTargets
        RUNTIME  DESTINATION
            lib/gostai/uobjects/${path}
        LIBRARY  DESTINATION
            lib/gostai/uobjects/${path}
        ARCHIVE  DESTINATION
            lib/gostai/uobjects/${path}
        INCLUDES DESTINATION
            include
    )
endfunction()

# A target named all does not fare well
uobject(uobject_all test test/all.uob/all.cc)
set_target_properties(uobject_all
    PROPERTIES
        OUTPUT_NAME all
)

uobject(lib-urbi test test/lib-urbi.uob/liburbi.cc)
uobject(remote test test/remote.uob/remote.cc)
uobject(machine test test/machine.uob/machine.cc test/machine.uob/umachine.cc)
uobject(generic test test/generic.uob/generic.cc)
uobject(ultest test test/ultest.uob/ultest.cc)
uobject(uaccess test test/uaccess.uob/uaccess.cc)
uobject(uaccess3 test test/uaccess3.uob/uaccess.cc)
uobject(uchange test test/uchange.uob/uchange.cc)
uobject(timer test  test/timer.uob/timer.cc)
uobject(threaded test test/threaded.uob/threaded.cc)
uobject(subsumption test test/subsumption.uob/subsumption.cc)
uobject(issue-3699 test test/issue-3699.uob/issue-3699.cc)
uobject(fusion urbi urbi/fusion.uob/fusion.cc)

find_package(ORTP QUIET)
if(ORTP_LIBRARIES)
    uobject(rtp urbi urbi/rtp.uob/rtp.cc)
    target_link_libraries(rtp ORTP)
endif()

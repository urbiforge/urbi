add_library(uco INTERFACE)
target_sources(uco INTERFACE
    src/details.cc
    src/uevent.cc
    src/uobject-common.cc
    src/uobject-hub-common.cc
    src/uprop.cc
    src/ustarter.cc
    src/utable.cc
    src/uvar-common.cc
    src/version-check.cc
    )

add_library(uco_urbi_main INTERFACE)
target_sources(uco_urbi_main INTERFACE src/urbi-main.cc)
add_library(uvalue INTERFACE)
target_sources(uvalue INTERFACE
    src/exit.cc
    src/package-info.cc
    src/ubinary.cc
    src/uimage.cc
    src/ulist.cc
    src/usound.cc
    src/uvalue-common.cc
    )
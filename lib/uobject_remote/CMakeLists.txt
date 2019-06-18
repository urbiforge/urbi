add_library(uobject_remote SHARED
    src/main.cc
    src/remote-ucontext-impl.hh
    src/ucallbacks.cc
    src/uobject.cc
    src/utimer-callback.cc
    src/uvar.cc
    )
target_compile_definitions(uobject_remote PRIVATE BUILDING_URBI_SDK LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")
target_link_libraries(uobject_remote
    PUBLIC urbi_headers port serialize jpeg Boost::boost Boost::dynamic_linking Boost::disable_autolinking Boost::regex Boost::date_time Boost::system Boost::thread
    PRIVATE uco uco_urbi_main uvalue urbi_sources ${CMAKE_DL_LIBS}
    )
set_target_properties(uobject_remote PROPERTIES OUTPUT_NAME uobject)

install(
    TARGETS uobject_remote
    EXPORT UrbiTargets
    RUNTIME DESTINATION lib/gostai/remote COMPONENT Runtime
    LIBRARY DESTINATION lib/gostai/remote COMPONENT Runtime
    ARCHIVE DESTINATION lib/gostai/remote COMPONENT SDK
)
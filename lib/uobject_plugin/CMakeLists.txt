set(UOBJECT_GENERATED_SRC src/pregenerated/ast/merged.cc)

include(sources.cmake)

add_library(uobject_plugin SHARED ${UOBJECT_PLUGIN_SRC} ${UOBJECT_GENERATED_SRC})
target_compile_definitions(uobject_plugin PRIVATE BUILDING_URBI_SDK BUILDING_URBI_MODULE __SRCDIR__="" LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")
target_include_directories(uobject_plugin PRIVATE src src/pregenerated include)
target_link_libraries(uobject_plugin
    PUBLIC urbi_headers port sched serialize Boost::boost Boost::dynamic_linking Boost::disable_autolinking Boost::regex Boost::signals Boost::filesystem Boost::date_time Boost::system Boost::thread
    PRIVATE uco uco_urbi_main uvalue urbi_root urbi_launch
    )
set_target_properties(uobject_plugin PROPERTIES OUTPUT_NAME uobject)

install(
    TARGETS uobject_plugin
    EXPORT UrbiTargets
    RUNTIME DESTINATION lib/gostai/engine COMPONENT Runtime
    LIBRARY DESTINATION lib/gostai/engine COMPONENT Runtime
    ARCHIVE DESTINATION lib/gostai/engine COMPONENT SDK
)
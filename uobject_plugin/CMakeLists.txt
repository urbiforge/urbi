if (HAVE_CUSTOM_BISON)
    include(${PROJECT_SOURCE_DIR}/cmake/custom_bison.cmake)
else ()
    MESSAGE("No bison specified, using pregenerated grammar and AST files.")

    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/parser/pregenerated/ ${CMAKE_CURRENT_BINARY_DIR}/src/parser/)
    execute_process(COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/src/ast/pregenerated/ ${CMAKE_CURRENT_BINARY_DIR}/src/ast/)

    set(UOBJECT_GENERATED_SRC
        ${CMAKE_CURRENT_BINARY_DIR}/src/ast/merged.cc
        )

endif (HAVE_CUSTOM_BISON)

include(${PROJECT_SOURCE_DIR}/cmake/sources.cmake)
if (NOT WIN32)
    list(APPEND UOBJECT_PLUGIN_SRC src/object/urbi/process.cc)
endif ()

add_library(uobject SHARED ${UCO_SRC} ${UOBJECT_PLUGIN_SRC} ${UOBJECT_GENERATED_SRC})

target_compile_definitions(uobject PRIVATE BUILDING_URBI_SDK BUILDING_URBI_MODULE __SRCDIR__="" LIBPORT_LIBSFX="" LIBPORT_LIBDIRNAME="lib")

target_include_directories(uobject
    PUBLIC $<INSTALL_INTERFACE:include/urbi>
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/sdk-remote/include>
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/src>
    PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    )

target_link_libraries(uobject
    port::port port::sched port::serialize Boost::boost Boost::dynamic_linking Boost::regex Boost::signals Boost::filesystem Boost::date_time Boost::system Boost::thread)

#set_target_properties(uobject
#    PROPERTIES
#    OUTPUT_NAME uobject
#    INSTALL_NAME_DIR "@executable_path/../lib/gostai/engine"
#    COMPILE_FLAGS
#    -DBUILDING_URBI_SDK
#    )

install(
    TARGETS uobject
    EXPORT UrbiTargets
    RUNTIME DESTINATION lib/gostai/engine COMPONENT Runtime
    LIBRARY DESTINATION lib/gostai/engine COMPONENT Runtime
    ARCHIVE DESTINATION lib/gostai/engine COMPONENT SDK
)
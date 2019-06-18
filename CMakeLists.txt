cmake_minimum_required(VERSION 3.14)
project(Urbi CXX C)

set(Urbi_VERSION 3.0.0)

set(CPACK_PACKAGE_VERSION ${Urbi_VERSION})
set(ConfigFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfig.cmake)
set(ConfigVersionFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfigVersion.cmake)
set(ConfigPackageLocation share/cmake/urbi)
set(CPACK_PACKAGE_VENDOR "Emys Inc.")
set(CPACK_WIX_UI_REF "WixUI_FeatureTree")
set(CPACK_WIX_UPGRADE_GUID "ba25c4f0-b795-44a6-a29e-d785bfa66806")
set(CPACK_WIX_PROPERTY_ALLUSERS "1")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
set(CPACK_WIX_CMAKE_PACKAGE_REGISTRY ${PROJECT_NAME})
add_definitions(-DBOOST_ALL_NO_LIB)
add_definitions(-DBOOST_ALL_DYN_LINK)
set(Boost_USE_DEBUG_RUNTIME OFF)

find_package(Boost COMPONENTS regex system filesystem thread chrono date_time signals REQUIRED)

if(NOT DEFINED GIT_REVISION)
    set(GIT_REVISION "custom_build")
endif()

include(CMakePackageConfigHelpers)
include(CPackComponent)

add_subdirectory(external/libjpeg)
add_subdirectory(external/libport)

install(
    TARGETS port sched serialize jpeg
    EXPORT UrbiTargets
    )

add_subdirectory(sdk-remote)
add_subdirectory(uobject_plugin)

add_subdirectory(share)
add_subdirectory(sdk-remote/src/uobjects)

install(
    DIRECTORY
        "${BOOSTROOT}/lib/"
    COMPONENT
        SDK
    DESTINATION
        lib
)

install(
    DIRECTORY
        "${BOOSTROOT}/bin/"
    COMPONENT
        Runtime
    DESTINATION
        bin
)

install(
    DIRECTORY
        "${BOOSTROOT}/include/"
    COMPONENT
        SDK
    DESTINATION
        include
)

write_basic_package_version_file(
        ${ConfigVersionFile}
    VERSION
        ${Urbi_VERSION}
    COMPATIBILITY
        AnyNewerVersion
)

export(
    EXPORT
        UrbiTargets
    NAMESPACE
        ${PROJECT_NAME}::
    FILE
        "${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiTargets.cmake"
)

configure_package_config_file(
    ${PROJECT_SOURCE_DIR}/cmake/UrbiConfig.cmake.in
    ${ConfigFile}
    INSTALL_DESTINATION
        ${ConfigPackageLocation}
)

install(
    EXPORT
        UrbiTargets
    FILE
        UrbiTargets.cmake
    NAMESPACE
        ${PROJECT_NAME}::
    COMPONENT
        SDK
    DESTINATION
        ${ConfigPackageLocation}
)

install(
    FILES
        ${ConfigVersionFile}
        ${ConfigFile}
    COMPONENT
        SDK
    DESTINATION
        ${ConfigPackageLocation}
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/misc/images/cube.ico
    COMPONENT
        Runtime
    DESTINATION
        share/icons
)

install(
    FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf
    COMPONENT
        Runtime
    DESTINATION
        .
)

cpack_add_component(Runtime
    DISPLAY_NAME
        "Runtime components"
    REQUIRED
)

cpack_add_component(SDK
    DISPLAY_NAME
        "SDK components for developers"
    DISABLED
)

cpack_add_component(Others
    DISPLAY_NAME
        "Other components"
    HIDDEN
)

include(CPack)
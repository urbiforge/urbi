cmake_minimum_required(VERSION 3.14)
project(Urbi CXX C)

set(Urbi_VERSION 3.0.0)

if (NOT DEFINED GIT_REVISION)
    set(GIT_REVISION "custom_build")
endif ()

if (WIN32)
    add_subdirectory(external/libjpeg)
endif ()

add_subdirectory(external/libport)

find_package(Boost COMPONENTS regex system filesystem thread chrono date_time signals REQUIRED)
add_subdirectory(lib/uco)
add_subdirectory(lib/uvalue)
add_subdirectory(lib/urbi)
add_subdirectory(lib/uobject_remote)
add_subdirectory(lib/uobject_plugin)
add_subdirectory(lib/urbi_launch)
add_subdirectory(share)

if (WIN32)
    install(DIRECTORY "${BOOSTROOT}/bin/" COMPONENT Runtime DESTINATION bin)
    install(DIRECTORY "${BOOSTROOT}/lib/" COMPONENT SDK DESTINATION lib)
    install(DIRECTORY "${BOOSTROOT}/include/" COMPONENT SDK DESTINATION include)
endif ()

include(CMakePackageConfigHelpers)
include(CPackComponent)
set(ConfigFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfig.cmake)
set(ConfigVersionFile ${CMAKE_CURRENT_BINARY_DIR}/cmake/UrbiConfigVersion.cmake)
set(ConfigPackageLocation share/cmake/urbi)

write_basic_package_version_file(${ConfigVersionFile}
    VERSION ${Urbi_VERSION}
    COMPATIBILITY AnyNewerVersion
    )

configure_package_config_file(${PROJECT_SOURCE_DIR}/cmake/UrbiConfig.cmake.in ${ConfigFile}
    INSTALL_DESTINATION ${ConfigPackageLocation}
    )

install(EXPORT UrbiTargets
    FILE UrbiTargets.cmake
    NAMESPACE ${PROJECT_NAME}::
    COMPONENT SDK
    DESTINATION ${ConfigPackageLocation}
    )

install(FILES ${ConfigVersionFile} ${ConfigFile}
    COMPONENT SDK
    DESTINATION ${ConfigPackageLocation}
    )

install(FILES share/images/urbi-logo/cube.ico
    COMPONENT Runtime
    DESTINATION share/icons
    )

install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf
    COMPONENT Runtime
    DESTINATION .
)

set(CPACK_PACKAGE_VERSION ${Urbi_VERSION})
set(CPACK_PACKAGE_VENDOR "Emys Inc.")
set(CPACK_WIX_UI_REF "WixUI_FeatureTree")
set(CPACK_WIX_UPGRADE_GUID "ba25c4f0-b795-44a6-a29e-d785bfa66806")
set(CPACK_WIX_PROPERTY_ALLUSERS "1")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.rtf")
set(CPACK_WIX_CMAKE_PACKAGE_REGISTRY ${PROJECT_NAME})
set(CPACK_WIX_PATCH_FILE "${CMAKE_CURRENT_SOURCE_DIR}/misc/cpack/wix_patch.xml")
set(CPACK_WIX_PRODUCT_ICON "${CMAKE_CURRENT_SOURCE_DIR}/share/images/urbi-logo/cube.ico")

cpack_add_component(Runtime
    DISPLAY_NAME "Runtime components"
    REQUIRED
    )

cpack_add_component(SDK
    DISPLAY_NAME "SDK components for developers"
    DISABLED
    )

include(CPack)
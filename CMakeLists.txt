cmake_minimum_required(VERSION 3.13...3.19 FATAL_ERROR)
project(libdogbarfcal VERSION 1.0.0 LANGUAGES C)
# define library before find packages to allow import of autotools projects (glib)
add_library(dogbarfcal
	src/simple_dog_barf.c
)

set_target_properties(dogbarfcal PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(dogbarfcal PROPERTIES SOVERSION 1)


#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(Dogbarfcal::dogbarfcal ALIAS dogbarfcal)

target_include_directories(dogbarfcal
	PUBLIC
	$<INSTALL_INTERFACE:include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        {CMAKE_CURRENT_SOURCE_DIR}/src
)

target_compile_options(dogbarfcal PRIVATE
    -Wall -Wextra -Werror -Wsequence-point -Wstrict-prototypes -Wshadow -Wmissing-prototypes -Wpedantic -fsanitize=address)

# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/Dogbarfcal)

install(TARGETS dogbarfcal
    EXPORT dogbarfcal-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#This is required so that the exported target has the name Dogbarfcal and not dogbarfcal
set_target_properties(dogbarfcal PROPERTIES EXPORT_NAME Dogbarfcal)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT dogbarfcal-targets
    FILE
        DogbarfcalTargets.cmake
    NAMESPACE
        Dogbarfcal::
    DESTINATION
        ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/DogbarfcalConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/DogbarfcalConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/DogbarfcalConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)


configure_file(${CMAKE_CURRENT_LIST_DIR}/cmake/dogbarfcal.pc.in
       ${CMAKE_CURRENT_BINARY_DIR}/dogbarfcal.pc
       @ONLY
)

#Install the config, configversion and custom find modules
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/DogbarfcalConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DogbarfcalConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/dogbarfcal.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)

export(EXPORT dogbarfcal-targets
    FILE ${CMAKE_CURRENT_BINARY_DIR}/DogbarfcalTargets.cmake
    NAMESPACE Dogbarfcal::)

export(PACKAGE Dogbarfcal)

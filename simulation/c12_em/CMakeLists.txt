#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(HPGe)
add_definitions(-std=c++11)
#----------------------------------------------------------------------------
# Find Geant4 package, activating all available UI and Vis drivers by default
# You can set WITH_GEANT4_UIVIS to OFF via the command line or ccmake/cmake-gui
# to build a batch mode only executable
#
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
  find_package(Geant4 REQUIRED ui_all vis_all)
else()
  find_package(Geant4 REQUIRED)
endif()

#----------------------------------------------------------------------------
# Setup Geant4 include directories and compile definitions
#
include(${Geant4_USE_FILE})

#----------------------------------------------------------------------------
# Find ROOT (optional package)
#
find_package(ROOT QUIET)
if(ROOT_FOUND)
  message(STATUS "G4 Examples: ROOT found. --> iort_therapy example with ROOT plotter enabled.")
  # Uncomment this line if suitable (some customization may be needed)
  add_definitions(-DG4ANALYSIS_USE_ROOT)
  include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR}
                    ${ROOT_INCLUDE_DIRS})
else()
  message(STATUS "G4 Examples: ROOT not found. --> iort_therapy example with ROOT plotter disabled.")
  include_directories(${PROJECT_SOURCE_DIR}/include
                    ${Geant4_INCLUDE_DIR})
endif()


#----------------------------------------------------------------------------
# Locate sources and headers for this project
#
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries
#
add_executable(HPGe HPGe.cc ${sources} ${headers})
if(ROOT_FOUND)
	target_link_libraries(HPGe ${Geant4_LIBRARIES} ${ROOT_LIBRARIES})
else()
	target_link_libraries(HPGe ${Geant4_LIBRARIES})
endif()

#----------------------------------------------------------------------------
# Copy all scripts to the build directory, i.e. the directory in which we
# build iort_therapy. This is so that we can run the executable directly because it
# relies on these scripts being in the current working directory.
#
set(EXAMPLEB2A_SCRIPTS
  gui.mac
  init_vis.mac
  vis.mac
  run1.mac
  run2.mac
  run3.mac
  )

foreach(_script ${EXAMPLEB2A_SCRIPTS})
  configure_file(
    ${PROJECT_SOURCE_DIR}/${_script}
    ${PROJECT_BINARY_DIR}/${_script}
    COPYONLY
    )
endforeach()

#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS HPGe DESTINATION bin)


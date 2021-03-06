cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GEM)
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

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../CMake_config")
set(Geant4_DIR /pnfs/opt/cemachines/geant4.9.6/lib64/Geant4-9.6.2)
find_package(cadmesh)

include(${Geant4_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include ${Geant4_INCLUDE_DIR}
${cadmesh_INCLUDE_DIR} ${ASSIMP_INCLUDE_DIRS})


set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${ASSIMP_CFLAGS_OTHER}")



#find_library(ASSIMP_LIBRARY assimp PATHS $ENV{ASSIMP_PATH}/lib)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc)

add_executable(GEMapp EXCLUDE_FROM_ALL GEMapp.cc ${sources})
target_link_libraries(GEMapp ${Geant4_LIBRARIES} ${cadmesh_LIBRARIES} )



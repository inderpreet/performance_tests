## @file    CMakeLists.txt
## @brief   Cmake File for VIDS Project
## @author  Inderpreet Singh

## For the uninitiated, create a folder named build and run the 
## command cmake .. && make 
## to make and build the executable

cmake_minimum_required (VERSION 2.8)

# Project Name
project (Test_Project)

set( CMAKE_BUILD_TYPE Debug )
set( CMAKE_CXX_FLAGS "-Wall -m64 -O3 -std=c++14 -pedantic -pthread -fno-omit-frame-pointer -g -finstrument-functions" )

# Version Info
set (APP_VERSION_MAJOR 1)
set (APP_VERSION_MINOR 0)
# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/include/app.h.in"
  "${PROJECT_BINARY_DIR}/app.h"
  )

## Find package OpenCV
# find_package( OpenCV REQUIRED )

## Include directories for the headers etc
include_directories( ${PROJECT_SOURCE_DIR}/include ${PROJECT_BINARY_DIR} )
 
#Can Add sources manually or
#set(SOURCES src/main.cpp /src/app.cpp)

## Source Files
file(GLOB SOURCES "./*.cpp" "./src/*.cpp")

# ----------- add the executable --------------------------
add_executable( test_app ${SOURCES} )

# ---------------------Generate Shared Library instead of binary --------
# Use STATIC instead of SHARED for .a
# add_library(myLib SHARED ${SOURCES} )
# Install location for library when sudo make install is run
# install( TARGETS myLib DESTINATION /usr/lib )
# use ldd to display shared libraries ldd myLib.so

# ---------------- Link existing libraries -------------------------------
# target_link_libraries( vids_linux_x64  ${OpenCV_LIBS} )


#------------------ Copy assets to build folder----------------------------
# add_custom_command(TARGET ${PROJECT_NAME}
#     POST_BUILD
#      COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/assets

#     COMMAND ${CMAKE_COMMAND} -E copy 
#     ${CMAKE_SOURCE_DIR}/assets/*.*
#     ${CMAKE_BINARY_DIR}/assets/
#     )

#---------------------- Linking Libraries -----------------------------------
#For the shared library:
# set ( PROJECT_LINK_LIBS libtestStudent.so )
# link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )
 
#For the static library:
#set ( PROJECT_LINK_LIBS libtestStudent.a )
#link_directories( ~/exploringBB/extras/cmake/studentlib_static/build )
 
# include_directories(~/exploringBB/extras/cmake/studentlib_shared/include)
 
# add_executable(libtest libtest.cpp)
# target_link_libraries(libtest ${PROJECT_LINK_LIBS} )
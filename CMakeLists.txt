cmake_minimum_required (VERSION 2.6)
project (OGL) 

set( CMAKE_CXX_FLAGS         "-O3 -g ")

FIND_PACKAGE( OpenCV REQUIRED )

find_package(OpenGL REQUIRED)
if(OpenGL_FOUND)
    link_directories(${OpenGL_INCLUDE_DIRS})
    include_directories(${OpenGL_LIBRARY_DIRS})
endif(OpenGL_FOUND)

IF(APPLE)
    link_directories(/opt/local/lib)
    include_directories(/System/Library/Frameworks/GLUT.framework/Headers)
    include_directories(/System/Library/Frameworks/OpenGL.framework/Headers)
ENDIF(APPLE)

if(UNIX)
    FIND_PATH(OPENGL_INC gl.h /usr/include/GL)
    include_directories(${OPENGL_INC})
endif(UNIX)

find_package(GLUT REQUIRED)
if ( GLUT_FOUND )
    message( "-- Found OpenGL Utility Toolkit" )
else ( GLUT_FOUND )
    message( SEND_ERROR "-- could not find OpenGL Utility Toolkit" )
endif ( GLUT_FOUND )

if(LINUX)
if ( GLUT_Xmu_LIBRARY )
    message( "-- Found X.Org X11 libXmu/libXmuu runtime libraries" )
else ( GLUT_Xmu_LIBRARY )
    message( SEND_ERROR "-- Could not find X.Org X11 libXmu/libXmuu runtime libraries" )
endif ( GLUT_Xmu_LIBRARY )

if ( GLUT_Xi_LIBRARY )
    message( "-- Found X.Org X11 libXi runtime library" )
else ( GLUT_Xi_LIBRARY )
    message( SEND_ERROR "-- Could not find X.Org X11 libXi runtime library" )
endif ( GLUT_Xi_LIBRARY )
endif(LINUX)

add_executable (ogl Main.cpp) 

target_link_libraries(ogl ${OPENGL_LIBRARY})
target_link_libraries(ogl ${GLUT_LIBRARIES})
TARGET_LINK_LIBRARIES( ogl ${OpenCV_LIBS} )

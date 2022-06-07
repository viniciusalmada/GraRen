cmake_minimum_required(VERSION 3.15.0)
project(GraRen VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED on)

###############################################################################
## GLOBAL VARIABLES
###############################################################################
if (UNIX)
add_compile_options(-Wall -Wextra -Werror)
elseif(WIN32)
add_compile_options(/W4 /WX)
endif(UNIX)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

###############################################################################
## GRAREN LIBRARY
###############################################################################
add_library(GraRen SHARED src/canvas.cpp
                src/circle.cpp
                src/color.cpp
                src/gl_handler.cpp
                src/line.cpp
                src/point.cpp
                src/rectangle.cpp
                )

target_include_directories(GraRen PRIVATE include vendor)

if(WIN32)
target_compile_definitions(GraRen PRIVATE GRAREN_DLL_EXPORT)
endif(WIN32)

if(WIN32)
target_link_libraries(GraRen ${PROJECT_SOURCE_DIR}/lib/win/GL3H/gl3h.lib)
endif(WIN32)
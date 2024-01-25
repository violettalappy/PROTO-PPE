# CMakeList.txt : CMake project for root application, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.12)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Enable options that you want
# option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

# Define project name
project ("app" 
VERSION 0.0.0 
LANGUAGES CXX C)

# set(SOURCEFILE_COMMON 
# "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h" 
# "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp" 
# )
# file(GLOB_RECURSE SOURCEFILE_ALL CONFIGURE_DEPENDS
# ${SOURCEFILE_COMMON}
# )
# Add source to this project's executable.
add_executable (app "src/main.cpp" "src/ProgramContext.h" "src/P3E/P3E_min.h" "src/ProgramContext.cpp")

# Linking include directories
set(1STPARTY
"${CMAKE_CURRENT_SOURCE_DIR}/src/"
)
set(3RDPARTY
#"${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/"
)
target_include_directories(${PROJECT_NAME} PUBLIC ${1STPARTY} PUBLIC ${3RDPARTY})

# Linking libraries
set(1STPARTY_LIB
)
set(3RDPARTY_LIB
winmm.lib
opengl32.lib
)

# 3RDPARTY Libraries
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/glfw")

target_link_libraries(${PROJECT_NAME} 
PRIVATE ${1STPARTY_LIB} 
PRIVATE ${3RDPARTY_LIB}
PRIVATE glfw
)

# TODO: why the heck does it need to specify if CMake is greater than 3.12
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET app PROPERTY CXX_STANDARD 20)
endif()

set_target_properties(app PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
    # NOTE: Before release to public, switch ON and resolve any warning error just to play nicely with compiler
    # For development, just default it to OFF, it will get in the way
    COMPILE_WARNING_AS_ERROR OFF
)

if (MSVC)
    target_compile_options(app PRIVATE /W4)
else()
    target_compile_options(app PRIVATE -Wall -Wextra -pedantic)
endif()

if(XCODE)
    set_target_properties(app PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal")
endif()

# TODO: Add tests and install targets if needed.

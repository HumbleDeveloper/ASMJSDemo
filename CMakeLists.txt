cmake_minimum_required(VERSION 2.8.12)
Project(HumbleASMJSDemo)

### pull in boilerplate cmake
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(BoilerPlate)
include(UtilityFunctions)
include(AssetUtilities)

# this sets the paths that cmake will use to locate libs (via the FindXXX.cmake or XXConfig.cmake scripts)
LIST(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/SDL2)

### Find Libraries
find_package(OpenGL)
find_package(SDL2 NO_CMAKE_FIND_ROOT_PATH)
add_subdirectory(lib/lodepng lodepng)

if(EMSCRIPTEN)
    set(OPENGL_gl_LIBRARY "")
endif()

CreateProgram(${PROJECT_NAME}
DIRS
    src
INCLUDES
    src
    ${SDL2_INCLUDE_DIRS}
LINK
    ${SDL2_LIBRARIES}
    ${OPENGL_gl_LIBRARY}
    lodepng
PROPERTIES
    FOLDER Executables
    MACOSX_BUNDLE_BUNDLE_NAME "Humble asm.js Demo"
    MACOSX_BUNDLE_BUNDLE_VERSION "1.0"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.humblebundle.HumbleAsmjsDemo"
    MACOSX_BUNDLE_COPYRIGHT "© 2015 Humble Bundle, Inc. "
)
source_group("Source" REGULAR_EXPRESSION "\\.(cpp|h)$")


if(EMSCRIPTEN)
    set(EM_TARGET_JS ${PROJECT_NAME}.js)
    configure_file(shell.html index.html @ONLY)
endif()

## this auto copies the needed libraries / frameworks over
CopyDependentLibs(${PROJECT_NAME})

if(NOT EMSCRIPTEN)
    CreateFolderMarkerFile(${PROJECT_NAME} asset_path.txt ${CMAKE_CURRENT_SOURCE_DIR}/assets)
endif()
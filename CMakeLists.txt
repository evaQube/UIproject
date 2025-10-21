cmake_minimum_required(VERSION 3.23)
project(UIproject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)

# Download and add SFML as a dependency
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(PROJECT_HEADERS 
    WidgetLibraryEvaQube/include/Core/WidgetModel.h
    WidgetLibraryEvaQube/include/Core/WidgetViewModel.h
    WidgetLibraryEvaQube/include/Core/WidgetView.h
    WidgetLibraryEvaQube/include/Core/AssetManager.h

    WidgetLibraryEvaQube/include/Button/ButtonModel.h
    WidgetLibraryEvaQube/include/Button/ButtonViewModel.h
    WidgetLibraryEvaQube/include/Button/ButtonView.h

    WidgetLibraryEvaQube/include/Image/ImageModel.h
    WidgetLibraryEvaQube/include/Image/ImageViewModel.h
    WidgetLibraryEvaQube/include/Image/ImageView.h

    WidgetLibraryEvaQube/include/Text/TextModel.h
    WidgetLibraryEvaQube/include/Text/TextViewModel.h
    WidgetLibraryEvaQube/include/Text/TextView.h
)


set(PROJECT_SOURCES 
    WidgetLibraryEvaQube/src/main.cpp
    WidgetLibraryEvaQube/src/Core/AssetManager.cpp

    WidgetLibraryEvaQube/src/Button/ButtonModel.cpp
    WidgetLibraryEvaQube/src/Button/ButtonViewModel.cpp
    WidgetLibraryEvaQube/src/Button/ButtonView.cpp

    WidgetLibraryEvaQube/src/Image/ImageModel.cpp
    WidgetLibraryEvaQube/src/Image/ImageViewModel.cpp
    WidgetLibraryEvaQube/src/Image/ImageView.cpp

    WidgetLibraryEvaQube/src/Text/TextModel.cpp
    WidgetLibraryEvaQube/src/Text/TextViewModel.cpp
    WidgetLibraryEvaQube/src/Text/TextView.cpp
)

set(PROJECT_FILES 
  ${PROJECT_HEADERS} 
  ${PROJECT_SOURCES}
)

include_directories(${PROJECT_NAME} PRIVATE WidgetLibraryEvaQube/include)

add_executable(${PROJECT_NAME} ${PROJECT_FILES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set Debugger Working Directory
set_property(TARGET ${PROJECT_NAME} PROPERTY 
    VS_DEBUGGER_WORKING_DIRECTORY 
    "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/$<CONFIG>")

# Copy the data directory after building
add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/data" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data"
)


target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_compile_definitions(${PROJECT_NAME} PUBLIC DEBUG_MODE=0)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()

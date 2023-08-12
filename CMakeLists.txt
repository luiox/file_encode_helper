cmake_minimum_required(VERSION 3.5)

project(file_encode_helper VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置 CMAKE_PREFIX_PATH 查找路径, 需要设置"D:/Qt/6.2.4/msvc2019_64/bin"到环境变量
set(CMAKE_PREFIX_PATH "D:/Qt/6.2.4/msvc2019_64")

set(QRC_SOURCE_FILES "res.qrc")
#qt_add_resources(QRC_SOURCE_FILES ${QRC_SOURCE_FILES})


find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainfrm.cpp
        src/mainfrm.h
        src/textfileencoder.cpp
        src/textfileencoder.h
        src/mainfrm.ui
        ${QRC_SOURCE_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(file_encode_helper
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET file_encode_helper APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(file_encode_helper SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(file_encode_helper
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(file_encode_helper PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(file_encode_helper PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS file_encode_helper
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(file_encode_helper)
endif()

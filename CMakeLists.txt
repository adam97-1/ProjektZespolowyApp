cmake_minimum_required(VERSION 3.5)

project(ProjektZespolowyApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Network)
set(PROJECT_SOURCES
        main.cpp
        MainWindow.cpp
        MainWindow.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProjektZespolowyApp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Wellcome.h Wellcome.cpp
        SelectDiscipline.h SelectDiscipline.cpp
        BaseWidget.h BaseWdget.cpp
        PushButton.h PushButton.cpp
        SelectCountry.h SelectCountry.cpp
        Result.h Result.cpp

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ProjektZespolowyApp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ProjektZespolowyApp SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ProjektZespolowyApp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ProjektZespolowyApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ProjektZespolowyApp PRIVATE Qt${QT_VERSION_MAJOR}::Network)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ProjektZespolowyApp)
endif()
set_target_properties(ProjektZespolowyApp PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ProjektZespolowyApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProjektZespolowyApp)
endif()

configure_file(${CMAKE_SOURCE_DIR}/Country_football.txt ${CMAKE_CURRENT_BINARY_DIR}/Country_football.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/Country_volleyball.txt ${CMAKE_CURRENT_BINARY_DIR}/Country_volleyball.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/Country_handball.txt ${CMAKE_CURRENT_BINARY_DIR}/Country_handball.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/Country_basketball.txt ${CMAKE_CURRENT_BINARY_DIR}/Country_basketball.txt COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/host.txt ${CMAKE_CURRENT_BINARY_DIR}/host.txt COPYONLY)

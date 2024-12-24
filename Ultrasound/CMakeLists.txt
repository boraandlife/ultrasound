cmake_minimum_required(VERSION 3.16)

project(Ultrasound VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt modüllerini bul ve projeye dahil et
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Charts)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Charts)

# Proje kaynaklarını tanımla
set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

# Yürütülebilir hedef oluştur
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Ultrasound
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Ultrasound SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Ultrasound
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Qt modüllerini hedefe bağla
target_link_libraries(Ultrasound PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Charts)

# iOS veya macOS için özellikler ekleme
if(${QT_VERSION_MAJOR} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Ultrasound)
endif()
set_target_properties(Ultrasound PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Kurulum dizinlerini ayarla
include(GNUInstallDirs)
install(TARGETS Ultrasound
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt 6 için uygulama oluşturmayı tamamla
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Ultrasound)
endif()

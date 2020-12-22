cmake_minimum_required(VERSION 3.5)

project(Proyecto LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(Proyecto SHARED

  )
else()
  add_executable(Proyecto
    knight.cpp
    knight.h
    bishop.cpp
    bishop.h
    chessboard.cpp
    chessboard.h
    chessbox.cpp
    chessbox.h
    chesspiece.cpp
    chesspiece.h
    game.cpp
    game.h
    king.cpp
    king.h
    main.cpp
    pawn.cpp
    pawn.h
    queen.cpp
    queen.h
    rook.cpp
    rook.h
    resource.qrc
  )
endif()

target_link_libraries(Proyecto PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

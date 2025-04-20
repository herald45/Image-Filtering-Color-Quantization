cmake_minimum_required(VERSION 3.10)
project(QtOpenCVApp)

set(CMAKE_CXX_STANDARD 17)

# Indique le chemin d’OpenCV et Qt
set(OpenCV_DIR "/opt/homebrew/Cellar/opencv/4.11.0_1")  # Mets ton chemin exact ici
set(Qt5_DIR "/opt/homebrew/Cellar/qt/6.8.2")  # Mets ton chemin exact ici

find_package(OpenCV REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

include_directories(${OpenCV_INCLUDE_DIRS})

# Ajoute le fichier source
#add_executable(app src/main.cpp src/filters.cpp )
add_executable(app src/MainWindow.cpp)
# Lien avec OpenCV et Qt
target_link_libraries(app ${OpenCV_LIBS} Qt6::Widgets)





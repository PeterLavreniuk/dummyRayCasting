cmake_minimum_required(VERSION 3.16)
project(dummyRayCasting)
set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED SDL2)

add_executable(dummyRayCasting src/main.cpp src/GameMap.cpp src/GameMap.h src/DummyTrooper.cpp src/DummyTrooper.h src/RcRenderer.cpp src/RcRenderer.h src/SolidObject.h src/SolidObject.cpp src/VisibleWall.h src/VisibleWall.cpp)

target_link_libraries(dummyRayCasting PRIVATE SDL2 SDL2_image)

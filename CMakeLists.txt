cmake_minimum_required(VERSION 3.17)
project(dummyRayCasting)

set(CMAKE_CXX_STANDARD 11)

find_package(SDL2 REQUIRED SDL2)

add_executable(dummyRayCasting src/main.cpp src/DummyVector.cpp src/DummyVector.h src/GameObject.cpp src/GameObject.h src/GameMap.cpp src/GameMap.h src/DummyTrooper.cpp src/DummyTrooper.h src/RcRenderer.cpp src/RcRenderer.h)

target_link_libraries(dummyRayCasting PRIVATE SDL2 SDL2_image)

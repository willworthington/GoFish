cmake_minimum_required(VERSION 3.12)
project(GoFish)

set(CMAKE_CXX_STANDARD 14)

add_executable(GoFish go_fish.cpp deck.h player.h deck.cpp player.cpp card.cpp)
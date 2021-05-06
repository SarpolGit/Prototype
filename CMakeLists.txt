cmake_minimum_required(VERSION 3.1)
project(PixelTactics)

FIND_PACKAGE(Boost 1.75.0 REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(position position.cpp)
add_library(card card.cpp)
add_library(deck deck.cpp)
add_library(player player.cpp)
add_library(hero hero.cpp)
#add_library(pole pole.cpp)


add_executable(main main.cpp)

target_link_libraries(main position)
target_link_libraries(main card)
#target_link_libraries(main pole)
target_link_libraries(main deck)
target_link_libraries(main hero)
target_link_libraries(main player)




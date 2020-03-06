cmake_minimum_required(VERSION 3.13)
project(newRush)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror")

set(CMAKE_CXX_STANDARD 98)


add_executable(NewRush
        AObject.h
        main.cpp BadGuys.cpp
        BadGuys.h WinFrame.cpp WinFrame.h pairMy.cpp pairMy.h Game.cpp Game.h Game.cpp Players.cpp Players.h Bullets.cpp Bullets.h SpaceOnBack.cpp SpaceOnBack.h)
#target_link_libraries( ${PROJECT_NAME} ncurses)
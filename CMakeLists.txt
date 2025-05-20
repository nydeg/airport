cmake_minimum_required(VERSION 3.29)
project(airport)


set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.6.2)
FETCHCONTENT_MAKEAVAILABLE(SFML)


add_executable(airport AirGame.cpp
        Airplane.cpp
        Airstrip.cpp
        Cargo.cpp
        Cilivian.cpp
        Date.cpp
        Game.cpp
        Menu.cpp
        Level.cpp
        Military.cpp
        Airplane.h
        Airstrip.h
        Cargo.h
        Cilivian.h
        Date.h
        Game.h
        Level.h
        Menu.h
        Military.h
        AirGame.cpp
        Display.h
        Display.cpp)


target_link_libraries(airport sfml-graphics)
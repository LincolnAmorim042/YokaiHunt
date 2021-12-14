cmake_minimum_required(VERSION 3.17)
project(yokaihunt)

set(CMAKE_CXX_STANDARD 14)

add_executable(yokaihunt main.cpp Battle.cpp Battle.h )


#set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics network REQUIRED)
include_directories(C:/SFML/include)
target_link_libraries(yokaihunt sfml-system sfml-window sfml-graphics sfml-audio)

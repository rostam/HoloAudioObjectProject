cmake_minimum_required(VERSION 3.10)
project(HoloAudioOBject)
set (CMAKE_CXX_STANDARD 17)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS})
file(GLOB BoostTestSrc "BoostTestSrc/*.cpp")
file(GLOB Src "Src/*.cpp")
add_executable(HoloAudioObject main.cpp ${Src})
add_executable(BoostTest ${BoostTestSrc} ${Src})
target_link_libraries(BoostTest ${Boost_LIBRARIES})

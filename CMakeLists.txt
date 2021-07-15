cmake_minimum_required(VERSION 3.19)
project(k_armed_bandit)

set(CMAKE_CXX_STANDARD 14)

add_executable(k_armed_bandit
        src/main.cpp
        src/multi_armed_bandit.hpp
        src/reinforcement_learning.hpp
        )
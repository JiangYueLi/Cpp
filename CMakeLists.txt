cmake_minimum_required(VERSION 3.23)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp main.cpp leetcode/299-getHint.cpp
        leetcode/215-findKthLargest.cpp
        leetcode/100233-minimumBoxes.cpp
        leetcode/100247-maximumHappinessSum.cpp
        leetcode/100251-shortestSubstrings.cpp
        leetcode/100216-maximumStrength.cpp
        leetcode/113-pathSum.cpp
        leetcode/46-permute.cpp)

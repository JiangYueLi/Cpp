cmake_minimum_required(VERSION 3.23)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp main.cpp
        leetcode/343-integerBreak.cpp
        leetcode/1823-findTheWinner.cpp
        leetcode/128-longestConsecutive.cpp
        leetcode/15-threeSum.cpp leetcode/2789-maxArrayValue.cpp)

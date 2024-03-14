cmake_minimum_required(VERSION 3.23)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp main.cpp
        leetcode/343-integerBreak.cpp
        leetcode/1823-findTheWinner.cpp
        leetcode/128-longestConsecutive.cpp
        leetcode/15-threeSum.cpp leetcode/2789-maxArrayValue.cpp leetcode/54-spiralOrder.cpp leetcode/48-rotate.cpp leetcode/84-largestRectangleArea.cpp leetcode/85-maximalRectangle.cpp leetcode/739-dailyTemperatures.cpp leetcode/503-nextGreaterElements.cpp
        leetcode/547-findCircleNum.cpp)

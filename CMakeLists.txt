cmake_minimum_required(VERSION 3.23)
project(Cpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(Cpp main.cpp
        leetcode/343-integerBreak.cpp
        leetcode/1823-findTheWinner.cpp
        leetcode/128-longestConsecutive.cpp
        leetcode/15-threeSum.cpp leetcode/2789-maxArrayValue.cpp leetcode/54-spiralOrder.cpp leetcode/48-rotate.cpp leetcode/84-largestRectangleArea.cpp leetcode/85-maximalRectangle.cpp leetcode/739-dailyTemperatures.cpp leetcode/503-nextGreaterElements.cpp
        leetcode/547-findCircleNum.cpp
        leetcode/684-findRedundantConnection.cpp
        leetcode/200-numIslands.cpp
        leetcode/924-minMalwareSpread.cpp
        leetcode/2312-sellingWood.cpp
        leetcode/1208-equalSubstring.cpp
        leetcode/1004-longestOnes.cpp
        leetcode/523-checkSubarraySum.cpp
        leetcode/974-subarraysDivByK.cpp
        leetcode/1094-carPooling.cpp
        leetcode/2684-maxMoves.cpp
        leetcode/1109-corpFlightBookings.cpp
        leetcode/5-longestPalindrome.cpp
        leetcode/100262-sumOfEncryptedInt.cpp
        leetcode/100209-unmarkedSumArray.cpp
        leetcode/100249-minimizeStringValue.cpp
        leetcode/303-NumArray.cpp
        leetcode/93-restoreIpAddresses.cpp
        leetcode/43-multiply.cpp
        leetcode/127-ladderLength.cpp
        leetcode/139-wordBreak.cpp
        leetcode/130-solve.cpp
        leetcode/529.cpp
        leetcode/934-shortestBridge.cpp
        leetcode/264-nthUglyNumber.cpp)

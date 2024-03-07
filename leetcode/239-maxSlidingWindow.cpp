//
// Created by huyihang on 2024/3/7.
//
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deque;
        vector<int> result;
        for(int i = 0,j = 1-k;i<nums.size();i++,j++)
        {
            if(j>0 && deque.front() == nums[j-1])
            {
                deque.pop_front();
            }

            while (!deque.empty() && deque.back()<nums[i])
            {
                deque.pop_back();
            }
            deque.push_back(nums[i]);

            if(j>=0)
            {
                result.push_back(deque.front());
            }
        }
        return result;
    }
};
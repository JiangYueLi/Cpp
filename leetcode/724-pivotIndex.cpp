//
// Created by huyihang on 2024/3/8.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumleft = 0;
        int sumright = accumulate(nums.begin(),nums.end(),0);
        for(int i =0;i<nums.size();i++)
        {
            sumright = sumright - nums[i];
            if(sumleft==sumright)
            {
                return i;
            }
            sumleft = sumleft+nums[i];
        }
        return -1;
    }
};
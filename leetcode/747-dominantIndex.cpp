#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max = -1;
        int nextmax = -1;
        int result = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(max<nums[i])
            {
                nextmax =max;
                max = nums[i];
                result = i;
            }
            else if(nums[i]>nextmax)
            {
                nextmax = nums[i];
            }
        }

        if(max >= 2*nextmax)
        {
            return result;
        }
        return -1;
    }
};
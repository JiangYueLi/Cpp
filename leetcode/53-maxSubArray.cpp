//
// Created by Y on 2024/3/3.
//


#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0;
        int maxans = nums[0];
        for(auto num:nums)
        {
            pre = max(pre+num,num);
            maxans = max(maxans,pre);
        }
        return maxans;
    }
};
//
// Created by huyihang on 2024/3/14.
//
#include <vector>

using namespace std;
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long res =nums[n-1];
        long long nowmax = nums[n-1];
        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i]<=nowmax)
            {
                nowmax = nowmax+nums[i];
                res = max(res,nowmax);
            }
            else
            {
                nowmax = nums[i];
                res = max(res,nowmax);
            }
        }
        return res;
    }
};
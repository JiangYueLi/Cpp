//
// Created by huyihang on 2024/3/12.
//

#include <vector>

using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()<2)
        {
            return nums[0];
        }
        int dp[nums.size()];
        dp[0] = nums[0];
        dp[1] = max(nums[1],dp[0]);
        int ans = max(dp[0],dp[1]);
        for(int i = 2;i<=nums.size()-1;i++)
        {
            dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
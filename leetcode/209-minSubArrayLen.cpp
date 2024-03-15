//
// Created by Y on 2023/9/5.
//
#include <vector>
#include <math.h>
#include<algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if(nums[0]>=target)
        {
            return 1;
        }
        int res = INT_MAX;
        int n = nums.size();
        int left =  0;
        int right = 0;
        int nowSum = 0;
        while (right<n && left<=right)
        {
            nowSum += nums[right];
            while (nowSum-nums[left]>=target)
            {
                nowSum -=nums[left];
                left++;

            }
            if(nowSum>=target)
            {
                res = min(res,right-left+1);
            }
            right++;
        }
        return res<=n?res:0;
    }
};
int main()
{
    Solution s;
    vector<int> a = {5};
    cout<<s.minSubArrayLen(7,a)<<endl;
}
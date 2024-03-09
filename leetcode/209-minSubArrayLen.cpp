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
        int left = 0;
        int right =1;
        if(nums[left] > target)
        {
            return 1;
        }
        if(nums.size()==1&& nums[0]<target)
        {
            return 0;
        }
        int res = INT_MAX;
        int now = nums[left];
        while(right<nums.size() && left<nums.size())
        {

           now += nums[right];
           while(now>=target&& left<=right)
           {
               res = min(res,right-left+1);
               now = now - nums[left];
               left++;

           }
            if(right == nums.size()-1 && left == 0 && now<target)
            {
                return 0;
            }
           right++;

        }
        return res;

    }
};
int main()
{
    Solution s;
    vector<int> a = {5};
    cout<<s.minSubArrayLen(7,a)<<endl;
}
//
// Created by Y on 2024/3/15.
//
#include <vector>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0;
        int count0 = 0;
        while (right<n)
        {
            if(nums[right] == 0)
            {
                count0++;
            }

            if (count0>k)
            {
                while(nums[left] !=0)
                {
                    left++;
                }
                left++;
                count0--;
            }
            res = max(res,right-left+1);
            right++;
        }
        return count0<k?n:res;
    }
};
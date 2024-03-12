//
// Created by huyihang on 2024/3/12.
//

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() ==0)
        {
            return 0;
        }
        vector<int> res(nums.size(),1);
        for(int i =1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    res[i] = max(res[j]+1,res[i]);
                }
            }
        }

        return *std::max_element(res.begin(),res.end());
    }
};
//
// Created by Y on 2024/3/9.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long long sum = 0;
        for(auto &num:nums)
        {
            if(num>0)
            {
                sum += num;
            } else
            {
                num = -num;
            }
        }
        sort(nums.begin(),nums.end());
        long long ret = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({nums[0], 0});
        for(int j=2;j<=k;j++)
        {
            auto [t,i] =pq.top();
            pq.pop();
            ret = t;
            if(i == nums.size()-1)
            {
                continue;
            }
            pq.push({t+nums[i+1],i+1});
            pq.push({t-nums[i]+nums[i+1],i+1});
        }
        return sum-ret;
    }
};
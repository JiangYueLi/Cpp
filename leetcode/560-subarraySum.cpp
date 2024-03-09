//
// Created by Y on 2024/3/3.
//
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
//        int n = nums.size();
//        int ans = 0;
//        for(int i = 0;i<n;i++)
//        {
//            int sum =0;
//            for (int end = i;end>=0;end--)
//            {
//                sum += nums[end];
//                if(sum == k)
//                {
//                    ans++;
//                }
//            }
//        }
//        return ans;
        int res= 0;
        unordered_map<int,int> map;
        map[0] =1;
        int sum =0;
        for(auto num:nums)
        {
            sum += num;
            res +=map[sum-k];
            map[sum]++;
        }
        return res;
    }
};
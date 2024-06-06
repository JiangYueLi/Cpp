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
        int sum = 0;
        unordered_map<int,int> map;
        map[0] =1;
        int res= 0;
        for(auto &num:nums)
        {
            sum += num;
            res += map[sum - k];
            map[sum]++;
        }
        return res;
    }
};
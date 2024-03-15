//
// Created by Y on 2024/3/15.
//
#include <vector>

#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        map[0] = -1;
        int sum = 0;
        for(int i =0;i< nums.size();i++)
        {
            sum += nums[i];
            int yu = sum%k;
            if(map.count(yu))
            {
                map[yu] = i;
            }
            else
            {
                if(i-map[yu] >1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
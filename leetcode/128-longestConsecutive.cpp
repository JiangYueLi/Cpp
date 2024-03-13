//
// Created by Y on 2024/3/13.
//
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for(auto &num:nums)
        {
            set.emplace(num);
        }
        int ans = 0;
        for(auto &sets:set)
        {
            if(!set.count(sets-1))
            {
                int nowNum = sets;
                int nowlength =1;
                while (set.count(nowNum+1))
                {
                    nowNum++;
                    nowlength++;
                }
                ans = max(ans,nowlength);
            }
        }
        return ans;
    }
};
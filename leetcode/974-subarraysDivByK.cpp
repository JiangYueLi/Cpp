//
// Created by Y on 2024/3/15.
//

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0;
        int sum = 0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(auto &num:nums)
        {
            sum += num;
            int yu = (sum%k+k)%k;
            if(map.count(yu))
            {
                res +=map[yu];
            }
            map[yu]++;
        }
        return res;
    }
};
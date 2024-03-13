//
// Created by Y on 2024/3/13.
//
#include <vector>

using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto &num:nums){
            ans ^=num;
        }
        return ans;
    }
};
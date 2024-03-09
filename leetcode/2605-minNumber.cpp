//
// Created by Y on 2023/9/5.
//
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        int res = 100;
        for(auto num1:nums1)
        {
            for(auto num2:nums2)
            {
                if(num1 == num2)
                {
                    res = min(res,num1);
                }
                else
                {
                    res = min(res,num1>num2?10*num2+num1:10*num1+num2);
                }
            }
        }
        return res;
    }
};
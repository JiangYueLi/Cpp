//
// Created by Y on 2024/3/13.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vectorString;
        for(auto &num:nums)
        {
            vectorString.push_back(to_string(num));
        }

        sort(vectorString.begin(),vectorString.end(),[](string left,string right)
        {
            return left+right>right+left;
        });

        string ans = "";
        for(auto &ss:vectorString)
        {
            ans +=ss;
        }
        return ans[0]=='0'?"0":ans;
    }
};
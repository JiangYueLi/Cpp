//
// Created by huyihang on 2024/3/7.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2)
        {
            return s;
        }
        vector<string> rows(numRows);
        int i = 0;
        int flag = -1;
        for(auto& c:s)
        {
            rows[i].push_back(c);
            if (i == 0 || i == numRows -1)
                flag = - flag;
            i += flag;
        }
        string ans = "";
        for(auto& row:rows)
        {
            ans += row;
        }
        return ans;
    }
};
//
// Created by Y on 2024/6/6.
//
#include <string>
using namespace std;
class Solution {
public:
    long long minimumSteps(string s) {
        long long ans =0;
        int cnt =0;
        for(auto &c:s)
        {
            if(c == '1')
            {
                cnt++;
            }
            else
            {
                ans += cnt;
            }
        }
        return ans;
    }
};
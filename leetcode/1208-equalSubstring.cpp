//
// Created by Y on 2024/3/15.
//

#include <string>

using namespace std;
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int res = 0;
        int sumCost = 0;
        int left =0;
        int right = 0;
        while(right<s.length() && left<=right)
        {
            sumCost += abs(s[right]-t[right]);
            while (sumCost>maxCost)
            {
                sumCost -=abs(s[left]-t[left]);
                left++;

            }

            res = max(res,right-left+1);
            right++;

        }
        return res;
    }
};
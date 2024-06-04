#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> recode;
        int n = s.size();
        int rk = -1;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(i!=0)
            {
                recode.erase(s[i-1]);
            }

            while(rk+1<n && !recode.count(s[rk+1]))
            {
                recode.insert(s[rk+1]);
                rk++;
            }
            ans = max(ans,rk -i +1);
        }
        return ans;
    }
};

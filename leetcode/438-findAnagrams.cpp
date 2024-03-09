//
// Created by Y on 2023/9/6.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.length();
        int pLen = p.length();
        if (sLen < pLen) {
            return {};
        }
        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }

        if(sCount == pCount)
        {
            ans.emplace_back(0);
        }
        for(int i =0;i<sLen-pLen;i++)
        {
            --sCount[s[i]-'a'];
            ++sCount[s[i+pLen]-'a'];
            if(sCount==pCount)
            {
                ans.emplace_back(i+1);
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    s.findAnagrams("cbaebabacd","abc");
    vector<int> a = {5,6,6};
    vector<int> b = {5,6,6};

}

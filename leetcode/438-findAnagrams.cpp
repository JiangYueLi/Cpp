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
        if(pLen>sLen)
        {
            return {};
        }

        vector<int> ans;
        vector<int> scount(26);
        vector<int> pcount(26);

        for(int i =0;i<pLen;i++)
        {
            scount[s[i] -'a']++;
            pcount[p[i] -'a']++;
        }
        if(scount == pcount)
        {
            ans.emplace_back(0);
        }

        for(int i =0;i<sLen-pLen;i++)
        {
            scount[s[i]-'a']--;
            scount[s[i+pLen]-'a']++;
            if(scount == pcount)
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

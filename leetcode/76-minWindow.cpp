//
// Created by Y on 2023/9/6.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n =s.length();
        int tot = 0;
        vector<int> c1;
        vector<int> c2;
        for(auto x:t)
        {
            c1[GetIndex(x)]++;
            if(c1[GetIndex(x)] == 1)
            {
                tot++;
            }
        }
        string ans = "";
        for(int i=0,j=0;i<n;i++)
        {
            int idx1 = GetIndex(s[i]);
            if(++c2[idx1]==c1[idx1]) tot--;
            while(j<i)
            {
                int idx2 = GetIndex(s[j]);
                if(c2[idx2]>c1[idx2])
                {
                    c2[idx2]--;
                    j++;
                }
                else{
                    break;
                }
            }
            if(tot == 0&&(ans.empty() || ans.length()>i-j+1))
            {
                ans = s.substr(j,i-j+1);
            }
        }
        return ans;
    }

    int GetIndex(char x)
    {
        return x-'A';
    }
};
int main()
{
    cout<<'Z' - 'A'<<endl;
}
//
// Created by huyihang on 2024/3/7.
//
#include <iostream>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slength = s.length();
        int tlength = t.length();
        int n=0,l = 0;
        while (n<slength && l<tlength)
        {
            if(s[n] == t[l])
            {
                n++;
            }
            l++;
        }
        return n == slength;
    }
};
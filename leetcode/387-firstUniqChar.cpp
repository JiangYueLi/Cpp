//
// Created by huyihang on 2024/3/6.
//
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {

        std::unordered_map<char,int> map;
        for(int i = 0;i<s.length();i++)
        {
            map[s[i]-'a']++;
        }
        for(int i = 0;i<s.length();i++)
        {
            if(map[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
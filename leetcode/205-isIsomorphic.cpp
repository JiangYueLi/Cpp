//
// Created by huyihang on 2024/3/6.
//

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map;
        unordered_set<char> set;
        for(int i=0;i<s.length();i++)
        {
            if(!map[s[i]])
            {
                if(set.count(t[i]))
                {
                    return false;
                }
                map[s[i]] = t[i];
                set.insert(t[i]);
            }

            if(map[s[i]] != t[i])
            {
                return false;
            }
        }
        return true;
    }
};
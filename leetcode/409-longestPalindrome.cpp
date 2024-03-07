//
// Created by huyihang on 2024/3/6.
//

#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int result = 0;
        for(auto& keys:s)
        {
            map[keys]++;
        }
        for(auto & maps:map)
        {
            result  += maps.second/2 *2;
            if(result%2 == 0 && maps.second%2==1)
            {
                result++;
            }
        }
        return result;
    }
};
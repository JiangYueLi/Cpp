//
// Created by huyihang on 2024/3/6.
//

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
//
//注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
//
//
//
//示例 1:
//
//输入: s = "anagram", t = "nagaram"
//输出: true
//示例 2:
//
//输入: s = "rat", t = "car"
//输出: false
//
//
//提示:
//
//1 <= s.length, t.length <= 5 * 104
//s 和 t 仅包含小写字母
#include<iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int> map;
        for(auto ss:s)
        {
            map[ss - 'a']++;
        }

        for(auto tt:t)
        {
            map[tt - 'a']--;
            if(map[tt - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};
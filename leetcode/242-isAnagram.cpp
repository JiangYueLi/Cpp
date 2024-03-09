//
// Created by Y on 2023/9/9.
//
/*
242. 有效的字母异位词
        简单
842
相关企业
        给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。



示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false


提示:

1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母*/

#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        unordered_map<char,int> smap;
        for(auto ss:s)
        {
            smap[ss]++;
        }

        for(auto tt:t)
        {
            if(smap.count(tt))
            {
                smap[tt]--;
                if(smap[tt]==0)
                {
                    smap.erase(tt);
                }
            }
            else{
                return false;
            }
        }
        if(smap.empty())
        {
            return true;
        }
        return false;

    }
};

int main()
{
    Solution s;
    s.isAnagram("anagram","nagaram");
}
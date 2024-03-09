//
// Created by Y on 2023/9/9.
//
//290. 单词规律
//        简单
//598
//相关企业
//        给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
//
//这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。
//
//
//
//示例1:
//
//输入: pattern = "abba", s = "dog cat cat dog"
//输出: true
//示例 2:
//
//输入:pattern = "abba", s = "dog cat cat fish"
//输出: false
//示例 3:
//
//输入: pattern = "aaaa", s = "dog cat cat dog"
//输出: false
//
//
//提示:
//
//1 <= pattern.length <= 300
//pattern 只包含小写英文字母
//1 <= s.length <= 3000
//s 只包含小写英文字母和 ' '
//s 不包含 任何前导或尾随对空格
//        s 中每个单词都被 单个空格 分隔

#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> str;
        stringstream iss(s);
        string word;
        while(iss>>word)
        {
            str.push_back(word);
        }
        if(str.size() != pattern.length())
        {
            return false;
        }
        unordered_map<char,string >pw;
        unordered_map<string ,char> wp;
        for (int i = 0; i < pattern.length(); ++i) {
            auto a = pattern[i];
            auto b = str[i];

            if(pw.count(a) && pw[a] != b) return false;
            if(wp.count(b) && wp[b] != a) return false;
            pw[a] = b;
            wp[b] = a;
        }
        return true;
    }
};
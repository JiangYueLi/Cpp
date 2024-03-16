//
// Created by Y on 2024/3/17.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string minimizeStringValue(string s) {
        int n = s.length();
        vector<int> count(26, 0); // 记录当前字符之前各个小写字母出现的次数
        string result;

        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                int minScore = INT_MAX;
                char minChar = 'z' + 1; // 初始化为一个比所有小写字母都大的字符

                // 遍历所有可能的替换字符
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    // 计算当前字符的分数
                    int score = 0;
                    for (int j = 0; j < 26; ++j) {
                        // 如果替换字符与之前的某个字符相同，则增加分数
                        score += count[j] * (ch - 'a' == j);
                    }

                    // 如果当前字符的分数更小，或者分数相同但字典序更小，则更新最小分数和最小字符
                    if (score < minScore || (score == minScore && ch < minChar)) {
                        minScore = score;
                        minChar = ch;
                    }
                }

                result += minChar;
                ++count[minChar - 'a']; // 更新当前字符的计数
            } else {
                result += s[i];
                ++count[s[i] - 'a']; // 更新当前字符的计数
            }
        }

        return result;
    }
};
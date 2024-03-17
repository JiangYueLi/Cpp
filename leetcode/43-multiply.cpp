//
// Created by Y on 2024/3/18.
//
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string s(m + n, '0');       //初始化大小m+n
        for(int i = m - 1; i >= 0; --i)     //从后向前
            for(int j = n - 1; j >= 0; --j)
            {
                int cur = (num1[i] - '0') * (num2[j] - '0') + (s[i+j+1] - '0'); //注意累加之前的结果
                s[i+j+1] = cur % 10 + '0';  //这里是=字符
                s[i+j] += cur / 10;     //注意这里是+=数字
            }
        for(int i = 0; i < m + n; ++i)
            if(s[i] != '0') return s.substr(i); //去除前导0
        return "0";
    }
};
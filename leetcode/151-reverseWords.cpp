#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        auto end = unique(s.begin(), s.end(), [](char a, char b) {
            return a == ' ' && b == ' ';
            });
        s.erase(end, s.end());

        if (s[0] == ' ')
            s.erase(0, 1);

        if (s[s.length()-1] == ' ')
            s.erase(s.length()-1, s.length());

        reverse(s.begin(), s.end());
        int left = 0;
       
        for (int i = 0; i < s.length() - 1; i++)
        {   
            if (s[i] ==  ' ')
            {
                reverse(s.begin() + left, s.begin() + i);
                left = i + 1;
            }
        }
        reverse(s.begin() + left, s.end());
        return s;
    }
};
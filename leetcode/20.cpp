//
// Created by huyihang on 2024/3/4.
//
#include <iostream>
#include <stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i <s.size(); i++)
        {
            if(s[i] == '(')
            {
                st.push(')');
            }
            else if(s[i] == '[')
            {
                st.push(']');
            }
            else if(s[i] == '{')
            {
                st.push('}');
            }
            else if (st.empty() || st.top() != s[i])
            {
                return false;
            } else
            {
                st.pop();
            }

        }
        return st.empty();
    }
};
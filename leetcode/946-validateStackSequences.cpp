//
// Created by huyihang on 2024/3/7.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stack;
        for(int i=0,j=0;i<pushed.size();i++)
        {
            stack.push(pushed[i]);
            while (!stack.empty() && stack.top() == popped[j]) {
                stack.pop();
                j++;
            }
        }
        return stack.empty();
    }
};
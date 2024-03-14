//
// Created by huyihang on 2024/3/14.
//


#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> stack;
        for(int i = 0;i<temperatures.size();i++)
        {
            while(!stack.empty()&& temperatures[stack.top()]<temperatures[i])
            {
                int cur = stack.top();
                res[stack.top()] = i-cur;
                stack.pop();
            }
            stack.push(i);
        }
        return res;
    }
};
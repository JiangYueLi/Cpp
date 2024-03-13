//
// Created by Y on 2024/3/13.
//


#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> stack;
        for(auto &num:arr)
        {
            if(stack.empty() || num>=stack.top())
            {
                stack.push(num);
            }
            else
            {
                int mx = stack.top();
                stack.pop();
                while (!stack.empty() && stack.top()>num)
                {
                    stack.pop();
                }
                stack.push(mx);
            }
        }
        return stack.size();
    }
};
//
// Created by huyihang on 2024/3/14.
//

#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> stack;
        heights.push_back(0);
        for(int i =0;i<heights.size();i++)
        {
            while (!stack.empty() && heights[stack.top()]>heights[i])
            {
                int cur = stack.top();
                stack.pop();
                int left = stack.empty()?0:stack.top()+1;;
                int right = i;
                ans = max(ans,(right-left)*heights[cur]);
            }
            stack.push(i);
        }
        return ans;
    }
};
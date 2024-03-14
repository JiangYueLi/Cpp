//
// Created by huyihang on 2024/3/14.
//

#include <vector>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        nums.insert(nums.end(),nums.begin(),nums.begin()+nums.size());
        vector<int> res(nums.size(),-1);
        stack<int> stack;
        for(int i =0;i<nums.size();i++)
        {
            while(!stack.empty()&&nums[stack.top()]<nums[i])
            {
                int cur = stack.top();
                res[cur] = nums[i];
                stack.pop();
            }
            stack.push(i);
        }
        vector<int> result(res.begin(),res.begin()+res.size()/2);
        return result;
    }
};
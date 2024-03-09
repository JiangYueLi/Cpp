//
// Created by Y on 2023/9/14.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:

    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return {};
        }
        if(nums.size()==1)
        {
            return {to_string(nums[0])};
        }
        int first = nums[0];
        int last = nums[0];
        vector<string> res;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i] != nums[i-1]+1)
            {
                res.emplace_back(getString(first,last));
                first = nums[i];
                last = nums[i];
            } else
            {
                last = nums[i];
            }
        }
        getString(first,last);
        res.emplace_back(getString(first,last));
        return res;
    }

    string getString(int first,int last)
    {
        if(first == last)
        {
            return to_string(first);
        }
        else
        {
            return to_string(first) + "->" + to_string(last);
        }
    }
};

int main()
{
    Solution s;
    vector<int> a = {-222,-221,0,2,3,4,6,8,9};
    for(auto b:s.summaryRanges(a))
    {
        cout<<b<<endl;
    }
}
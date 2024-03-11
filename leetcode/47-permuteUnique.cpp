//
// Created by huyihang on 2024/3/11.
//
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void back(vector<int>& nums,vector<bool>& on_path)
    {
        if(path.size() == nums.size())
        {
            res.emplace_back(path);
            return;
        }
        for(int i = 0;i<nums.size();i++)
        {

            if(on_path[i] ==false)
            {
                path.emplace_back(nums[i]);
                on_path[i] = true;
                back(nums,on_path);
            }
            else
            {
                continue;
            }
            path.pop_back();
            on_path[i] = 0;

        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> on_path(nums.size(),false);
        back(nums,on_path);
        sort(res.begin(),res.end());
        auto last = unique(res.begin(),res.end());
        res.erase(last,res.end());
        return res;
    }
};
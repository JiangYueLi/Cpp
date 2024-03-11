//
// Created by huyihang on 2024/3/11.
//

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> state;
        sort(candidates.begin(),candidates.end());
        int start = 0;
        vector<vector<int>> res;
        backtrack(state,target,candidates,start,res);
        return res;
    }

    void backtrack(vector<int> &state,int target,vector<int> &candidates,int start,vector<vector<int>> &res)
    {
        if(target == 0)
        {
            res.push_back(state);
            return;
        }

        for(int i =start;i<candidates.size();i++)
        {
            if(target-candidates[i]<0)
            {
                break;
            }
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            state.push_back(candidates[i]);
            backtrack(state,target-candidates[i],candidates,i+1,res);
            state.pop_back();
        }
    }
};
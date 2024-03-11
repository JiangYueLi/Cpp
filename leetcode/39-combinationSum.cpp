//
// Created by huyihang on 2024/3/11.
//

#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> state;
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
        }

        for(int i =start;i<candidates.size();i++)
        {
            if(target-candidates[i]<0)
            {
                break;
            }
            state.push_back(candidates[i]);
            backtrack(state,target-candidates[i],candidates,i,res);
            state.pop_back();
        }
    }
};

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {

public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortarr = arr;
        sort(sortarr.begin(),sortarr.end());
        unordered_map<int ,int > ranks;
        vector<int> ans(arr.size());
        for(auto &a:sortarr)
        {
            if(!ranks.count(a))
            {
                ranks[a] = ranks.size()+1;
            }
        }
        for(int i =0;i<arr.size();i++)
        {
            ans[i] = ranks[arr[i]];
        }
        return ans;
    }
};
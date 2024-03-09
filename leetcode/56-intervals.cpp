//
// Created by Y on 2023/9/14.
//

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            return a[0]<b[0];
        });

        vector<vector<int>> res;

        int n = intervals.size();
        for (int j = 0; j < n; ++j) {
            int first = intervals[j][0];
            int last =  intervals[j][1];

            while(j+1<n)
            {
                if(intervals[j+1][0]<=last)
                {
                    last = max(last,intervals[j+1][1]);
                    j++;
                }
                else
                {
                    break;
                }

            }
            vector<int> a= {first,last};
            res.emplace_back(a);
        }
        return res;
    }
};


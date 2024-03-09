//
// Created by Y on 2023/9/14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());

        int count = 0;
        int n = points.size();
        for(int i = 0;i<n;i++)
        {
            int first = points[i][0];
            int last =  points[i][1];

            while(i+1<n)
            {
                if((points[i+1][0]<=first && points[i+1][1]>=last))
                {
                    first = max(first,points[i+1][0]);
                    last  = min(last,points[i+1][1]);
                    i++;
                }
                else if((points[i+1][0]<=last && points[i+1][1]>=first))
                {
                    first = max(first,points[i+1][0]);
                    last  = min(last,points[i+1][1]);
                    i++;
                }
                else
                {
                    break;
                }
            }
            count++;
        }

        return count;
    }
};
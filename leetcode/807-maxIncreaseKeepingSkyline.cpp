#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> rwoMax(m,0);
        vector<int> colMax(n,0);
        for(int i= 0;i<m;i++)
        {
            for(int j= 0;j<n;j++)
            {
                rwoMax[i] = max(rwoMax[i],grid[i][j]);
                colMax[j] = max(colMax[j],grid[i][j]);
            }
        }

        for(int i= 0;i<m;i++)
        {
            for(int j= 0;j<n;j++)
            {
                res += min(rwoMax[i],colMax[j]) - grid[i][j];
            }
        }
        return res;
    }
};
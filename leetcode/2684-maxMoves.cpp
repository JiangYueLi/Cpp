//
// Created by Huyihang on 2024/3/16.
//


#include <vector>
using namespace std;

class Solution {
public:
    int  check (int x,int y,vector<vector<int>>& grid)
    {
        int col = grid.size();
        int row = grid[0].size();
        int now = grid[x][y];
        int ans1 =0;int ans2 =0;int ans3 = 0;
        if(x-1>=0 && y+1<row && grid[x-1][y+1]>now)
        {
            grid[x][y] =0;
            ans1 =  1 + check(x-1,y+1,grid);
        }

        if(x<col && y+1<row && grid[x][y+1]>now)
        {
            grid[x][y] =0;
            ans2 = 1+check(x,y+1,grid);
        }

        if(x+1<col && y+1<row && grid[x+1][y+1]>now)
        {
            grid[x][y] =0;
            ans3 = 1+check(x+1,y+1,grid);
        }

        return max(ans1,max(ans2,ans3));
    };
    int maxMoves(vector<vector<int>>& grid) {
        int col = grid.size();
        int ans = 0;
        for(int i =0;i<col;i++)
        {
            ans = max(ans,check(i,0,grid));
        }

        return ans;
    }
};
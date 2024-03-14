//
// Created by Y on 2024/3/14.
//

#include <vector>

using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count =0;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0;i<row;i++)
        {
            for(int j =0;j<col;j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                }
                search(i,j,row,col,grid);
            }
        }
        return count;
    }

    void search(int i,int j,int row,int col,vector<vector<char>>& grid)
    {
        if(inarea(i,j,row,col) && grid[i][j] == '1')
        {
            grid[i][j] ='2';
            search(i-1,j,row,col,grid);
            search(i+1,j,row,col,grid);
            search(i,j-1,row,col,grid);
            search(i,j+1,row,col,grid);
        }
    }
    bool inarea(int i,int j,int row,int col)
    {
        return (i>=0) && (i<row) && (j>=0)&& (j<col);
    }
};
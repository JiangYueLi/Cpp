//
// Created by Y on 2024/3/18.
//

#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> dirs={{-1,-1},{-1,0},{-1,+1},{0,-1},{0,+1},{+1,-1},{+1,0},{+1,+1}};

    bool change(vector<vector<char>>& board,int i,int j,
                const vector<vector<char>>& originalBoard)
    {
        int mineNum = 0;
        bool changed2Num = false;
        for(int a = i-1;a<=i+1;++a)
            for(int b = j-1;b<=j+1;++b)
            {
                if(a<0||a>=board.size()||b<0||b>=board[0].size())
                    continue;
                if(a==i&&b==j)
                    continue;

                if(originalBoard[a][b]=='M')
                    mineNum++;
            }

        if(mineNum==0)
            board[i][j] = 'B';
        else
        {
            board[i][j] = '0'+mineNum;
            changed2Num = true;
        }
        return changed2Num;
    }

    void dfs(vector<vector<char>>& board,vector<int> click,vector<vector<int>>& visited,
             const vector<vector<char>>& originalBoard)
    {
        int i = click[0];
        int j = click[1];
        if(i<0||i>=board.size()||j<0||j>=board[0].size()||visited[i][j]==1)
            return;

        visited[i][j] = 1;
        if(board[i][j]=='M')
        {
            board[i][j]='X';
            return;
        }
        else if(board[i][j]=='E')
        {
            if(!change(board,i,j,originalBoard))
            {
                for(int k=0;k<8;++k)
                {
                    vector<int> nextClick(click);
                    nextClick[0] = click[0] + dirs[k][0];
                    nextClick[1] = click[1] + dirs[k][1];
                    dfs(board,nextClick,visited,originalBoard);
                }
            }

        }
        return;
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<char>> updatedBoard(board);
        int m = board.size();
        if(m==0)
            return updatedBoard;
        int n = board[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        dfs(updatedBoard,click,visited,board);
        return updatedBoard;
    }
};
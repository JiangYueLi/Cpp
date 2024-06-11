//
// Created by Y on 2024/6/11.
//
#include <vector>

using namespace std;
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        int res = 0;
        for(int i = 0;i<row;i++) {
            for(int j = 0;j<col;j++) {
                if(board[i][j] == 'X') {
                    board[i][j] = '.';
                    res++;
                    ganran(board,i,j);
                }
            }
        }
        return res;
    }

    void ganran(vector<vector<char>>& board,int i,int j) {

        int k = i+1;
        while(k<board.size() && board[k][j] == 'X') {
            board[k][j] = '.';
            k++;
        }
        int q = j+1;
        while(q<board[0].size() && board[i][q] == 'X') {
            board[i][q] = '.';
            q++;
        }
    }
};
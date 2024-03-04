//
// Created by huyihang on 2023/9/13.
//
/*
给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非递减顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。



示例 1：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
输出：true
示例 2：


输入：matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
输出：false


提示：

m == matrix.length
        n == matrix[i].length
1 <= m, n <= 100
-104 <= matrix[i][j], target <= 104*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
            return false;
        int row = 0, col = matrix[0].size()-1;
        while(row < matrix.size() && col >= 0){
            if(matrix[row][col] < target)
                row++;
            else if(matrix[row][col] > target)
                col--;
            else
                return true;
        }
        return false;

    }
};

int main()
{
    Solution s;
    vector<int> a ={1};
    vector<vector<int>> b;
    b.emplace_back(a);
    cout<<s.searchMatrix(b,0)<<endl;
}


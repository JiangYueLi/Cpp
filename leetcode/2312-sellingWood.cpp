//
// Created by Y on 2024/3/15.
//

#include <vector>

using namespace std;
class Solution {
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<long long>> dp(m+1,vector<long long>(n+1));
        for(auto &price:prices)
        {
            dp[price[0]][price[1]] =price[2];
        }
        for(int i =0;i<=m;i++)
        {
            for(int j = 0;j<=n;j++)
            {
                for(int k =1;k<=j/2;k++) dp[i][j] = max(dp[i][j],dp[i][k]+dp[i][j-k]);
                for(int k =1;k<=i/2;k++) dp[i][j] = max(dp[i][j],dp[k][j]+dp[i-k][j]);
            }
        }
        return dp[m][n];
    }
};
//
// Created by Y on 2024/3/14.
//

#include <vector>

using namespace std;
class Solution {
public:
    int find(int x,vector<int> &parent)
    {
        while (x!= parent[x])
        {
            x = parent[x];
        }
        return x;
    }

    void Union(int x,int y,vector<int> &parent)
    {
        int fx = find(x,parent);
        int fb = find(y,parent);
        if(fx !=fb)
        {
            parent[fb] =fx;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // 初始化时每个节点的父节点就是自身
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1)
                {
                    Union(i,j,parent);
                }
            }
        }
        int ans=0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == i) {
                ans++;
            }
        }
        return ans;
    }
};
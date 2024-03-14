//
// Created by Y on 2024/3/14.
//
#include <vector>

using namespace std;
class Solution {
public:
    int find(int x,vector<int>& parent)
    {
        while(x != parent[x])
        {
            x = parent[x];
        }
        return x;
    }

    void Union(int x,int y,vector<int>& parent)
    {
        int fx = find(x,parent);
        int fy = find(y,parent);
        if(fx !=fy)
        {
            parent[fx] =fy;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i] = i;
        }

        for(auto &edge:edges)
        {
            int x= edge[0], y= edge[1];
            if(find(x,parent) != find(y,parent))
            {
                Union(x,y,parent);
            }
            else
            {
                return edge;
            }
        }
        return {};
    }
};
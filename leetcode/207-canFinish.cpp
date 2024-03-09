//
// Created by Y on 2023/9/9.
//
/*
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。



示例 1：

输入：numCourses = 2, prerequisites = [[1,0]]
        输出：true
解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：

输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
输出：false
解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。


提示：

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
        prerequisites[i] 中的所有课程对 互不相同*/
#include<iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n  = prerequisites.size();
        if(n==0)
        {
            return true;
        }
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adjacency(numCourses);
        queue<int> help;
        for(auto prerequisite:prerequisites)
        {
            indegree[prerequisite[0]]++;
            adjacency[prerequisite[1]].push_back(prerequisite[0]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
                help.push(i);
        }
        int count = 0;
        while(!help.empty())
        {
            int visited = help.front();
            count++;
            help.pop();
            for(int i =0;i<adjacency[visited].size();i++)
            {
                indegree[adjacency[visited][i]]--;
                if(indegree[adjacency[visited][i]]==0)
                {
                    help.push(adjacency[visited][i]);
                }
            }
        }
        return count == numCourses;
    }
};

int main()
{
    return 0;
}
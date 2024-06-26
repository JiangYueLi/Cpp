//
// Created by huyihang on 2023/9/12.
//
/*
你正在玩一款电子游戏，在游戏中你需要保护城市免受怪物侵袭。给你一个 下标从 0 开始 且长度为 n 的整数数组 dist ，其中 dist[i] 是第 i 个怪物与城市的 初始距离（单位：米）。

怪物以 恒定 的速度走向城市。给你一个长度为 n 的整数数组 speed 表示每个怪物的速度，其中 speed[i] 是第 i 个怪物的速度（单位：米/分）。

怪物从 第 0 分钟 时开始移动。你有一把武器，并可以 选择 在每一分钟的开始时使用，包括第 0 分钟。但是你无法在一分钟的中间使用武器。这种武器威力惊人，一次可以消灭任一还活着的怪物。

一旦任一怪物到达城市，你就输掉了这场游戏。如果某个怪物 恰 在某一分钟开始时到达城市，这会被视为 输掉 游戏，在你可以使用武器之前，游戏就会结束。

返回在你输掉游戏前可以消灭的怪物的 最大 数量。如果你可以在所有怪物到达城市前将它们全部消灭，返回  n 。



示例 1：

输入：dist = [1,3,4], speed = [1,1,1]
输出：3
解释：
第 0 分钟开始时，怪物的距离是 [1,3,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,2,3]，你没有消灭任何怪物。
第 2 分钟开始时，怪物的距离是 [X,1,2]，你消灭了第二个怪物。
第 3 分钟开始时，怪物的距离是 [X,X,1]，你消灭了第三个怪物。
所有 3 个怪物都可以被消灭。
示例 2：

输入：dist = [1,1,2,3], speed = [1,1,1,1]
输出：1
解释：
第 0 分钟开始时，怪物的距离是 [1,1,2,3]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,1,2]，你输掉了游戏。
你只能消灭 1 个怪物。
示例 3：

输入：dist = [3,2,4], speed = [5,3,2]
输出：1
解释：
第 0 分钟开始时，怪物的距离是 [3,2,4]，你消灭了第一个怪物。
第 1 分钟开始时，怪物的距离是 [X,0,2]，你输掉了游戏。
你只能消灭 1 个怪物。


提示：

n == dist.length == speed.length
1 <= n <= 105
1 <= dist[i], speed[i] <= 105*/

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> time;
        for (int i = 0; i < dist.size(); ++i) {
            time.push_back((dist[i]%speed[i]==0)?(dist[i]/speed[i]):(dist[i]/speed[i]+1));
        }
        sort(time.begin(),time.end(),[](int a,int b){
            return a<b;
        });
        for(int i=0;i<time.size();i++)
        {
            if(i+1> time[i])
            {
                return i;
            }
        }
        return time.size();
    }
};

int main()
{
    Solution p;
    vector<int> a ={3,2,4};
    vector<int> b ={5,3,2};
    cout<<p.eliminateMaximum(a,b)<<endl;
    return 0;
}
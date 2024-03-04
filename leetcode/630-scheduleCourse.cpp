//
// Created by huyihang on 2023/9/11.
//
/*
这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。



示例 1：

输入：courses = [[100, 200], [1100, 1300], [100, 1400], [100,1400]]
输出：3
解释：
这里一共有 4 门课程，但是你最多可以修 3 门：
首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。
示例 2：

输入：courses = [[1,2]]
        输出：1
示例 3：

输入：courses = [[3,2],[4,3]]
输出：0


提示:

1 <= courses.length <= 104
1 <= durationi, lastDayi <= 104*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int> &a,vector<int> &b){
            return a[1]<b[1];
        });
        priority_queue<int> q;
        int totaltime = 0;
        for(auto &course:courses)
        {
            if(totaltime+course[0]<=course[1])
            {
                q.push(course[0]);
                totaltime += course[0];
            }
            else if(!q.empty()&&course[0]<q.top())
            {
                totaltime -=q.top();
                totaltime +=course[0];
                q.pop();
                q.push(course[0]);
            }
        }
        return q.size();
    }
};

int main()
{
    Solution p;
    vector<int> a= {100, 200};
    vector<int> b= {1200, 1300};
    vector<int> c= {100, 1400};
    vector<int> d= {100,1400};
    vector<int> g= {100,1400};
    vector<vector<int>> f;
    f.emplace_back(a);
    f.emplace_back(b);
    f.emplace_back(c);
    f.emplace_back(d);
    f.emplace_back(g);
    cout<<p.scheduleCourse(f)<<endl;
    return 0;
}
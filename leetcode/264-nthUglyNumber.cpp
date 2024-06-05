//
// Created by huyihang on 2024/3/12.
//


#include <vector>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
//        vector<int> res(n);
//        int a =0,b=0,c=0;
//        res[0] =1;
//        for(int i =1;i<n;i++)
//        {
//            int n2= res[a] *2,n3 = res[b]*3,n5 = res[c]*5;
//            res[i] = min(min(n2,n3),n5);
//            if(res[i] == n2) a++;
//            if(res[i] == n3) b++;
//            if(res[i] == n5) c++;
//        }
//        return res[n-1];

        int nums[] = {2,3,5};
        set<int> s;
        priority_queue<long,vector<long>,greater<long>> q;
        s.insert(1);
        q.push(1);
        for(int i = 1;i<=n; i++)
        {
            long x = q.top();
            q.pop();
            if(i == n)
            {
                return x;
            }
            for(auto &num:nums)
            {
                long t = x*num;
                if(!s.count(t))
                {
                    s.insert(t);
                    q.push(t);
                }
            }
        }
        return -1;
    }
};
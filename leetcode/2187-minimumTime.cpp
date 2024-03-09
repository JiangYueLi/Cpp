//
// Created by Y on 2023/9/7.
//
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int min = *min_element(time.begin(),time.end());
        long long right = 1L* min *totalTrips;
        long long left = 1;
        long long k = right;
        while(left< right)
        {
            long long mid = (left+right)/2;
            long long totaltime = 0;
            for(auto t:time)
            {
                totaltime +=mid/t;
            }

            if(totaltime<totalTrips)
            {
                left = mid+1;

            }
            else
            {
                right = mid;
                k = mid;
            }

        }
        return  k;
    }
};

int main()
{
    Solution p;
    vector<int> a = {1,2,3};
    cout<<p.minimumTime(a,10000000)<<endl;
}
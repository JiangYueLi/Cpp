//
// Created by huyihang on 2024/3/11.
//

#include <iostream>

using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return N>0?quickMul(x,N)/1.0:1.0/ quickMul(x,-N);
    }

    double quickMul(double x,long long N)
    {
        double ans = 1.0;
        double x_contribute = x;
        while(N>0)
        {
            if(N%2 ==1)
            {
                ans *=x_contribute;
            }
            x_contribute *=x_contribute;
            N = N/2;
        }

        return ans;
    }
};

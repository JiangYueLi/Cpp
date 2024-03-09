//
// Created by Y on 2023/9/7.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int min = *min_element(ranks.begin(),ranks.end());
        long long left = 0;
        long long right = 1LL * min * cars *cars;
        while(left+1<right)
        {
            long long mid = (left+right)/2;
            long long s = 0;
            for(auto r:ranks)
            {
                s +=sqrt(mid/r);
            }
            (s>=cars?right:left) = mid;
        }
        return right;
    }
};

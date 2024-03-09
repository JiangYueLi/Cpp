//
// Created by Y on 2023/9/5.
//
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i = low;i<=high;i++)
        {
            auto s = to_string(i);
            int n = s.length();
            if(n %2 ==0 && accumulate(s.begin(),s.begin()+n/2,0)==accumulate(s.begin()+n/2,s.begin()+n,0))
            {
                ans++;
            }
        }
        return ans;
    }
};
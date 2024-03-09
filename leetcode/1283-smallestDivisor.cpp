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
    int smallestDivisor(vector<int>& nums, int threshold) {
        int max = *max_element(nums.begin(),nums.end());
        int left = 1;
        int right = max;
        int k = max;
        while(left<right)
        {
            int mid = (left+right)/2;
            int total = 0;
            for(auto num:nums)
            {
                total += ((num%mid ==0)?(num/mid):(num/mid+1));
            }
            if(total>threshold)
            {
                left = mid+1;
            }
            else
            {
                k = mid;
                right = mid;

            }
        }
        return k;
    }
};

int main()
{
    Solution p;
    vector<int> a = {1,2,5,9};
    cout<<p.smallestDivisor(a,6)<<endl;
}
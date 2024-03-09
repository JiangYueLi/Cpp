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
    int minEatingSpeed(vector<int>& piles, int h) {
        int max = *max_element(piles.begin(),piles.end());
        int left = 1;
        int right = max;
        int k =right;
        while(left<right)
        {
            int mid = (left+right)/2;
            int totalTime = 0;
            for(auto p:piles)
            {
                totalTime +=p/mid;
                if(p%mid !=0) {
                    totalTime++;
                }
            }
            if(totalTime>h)
            {
                left=mid+1;
            }
            else if(totalTime<=h)
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
    vector<int> a = {3,6,7,11};
    cout<<p.minEatingSpeed(a,4)<<endl;
}
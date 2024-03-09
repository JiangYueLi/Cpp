#include <iostream>
#include <vector>
#include<math.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        
        int ans = 0;
        int end = 0;
        int maxpos = 0;
        for(int i =0;i<nums.size()-1;i++)
        {
            maxpos = max(nums[i]+i,maxpos);
            if(i == end)
            {
                ans++;
                end = maxpos;
            }
            if(end>nums.size())
            {
                return ans;
            }
            
        }
         return ans;
    }
};
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int addsum =0;
        int ans=0;
        int num = 0;
        for(auto &a:nums)
        {
            if(a % 3 == 0 && a%2 ==0)
            {
                addsum +=a;
                num++;
            }
        }
         if(num != 0)
        {
             ans = addsum/num;
        }
        return ans;
    }
};
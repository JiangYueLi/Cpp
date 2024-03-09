#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = *max_element(candies.begin(),candies.end());
        vector<bool> res;

        for(auto c: candies)
        {
            if(c + extraCandies >= max)
            {
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }
        
        return res;
    }
};

int main()
{
    Solution p;
    vector<int> a = {1,3,4,5};
    for(auto r: p.kidsWithCandies(a,1))
    {
        std::cout<<r<<std::endl;
    }
}
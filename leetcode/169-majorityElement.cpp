#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int candidate = 0;
        for(const auto &t:nums)
        {
            if(!cnt)
                candidate = t;
            cnt += candidate == t?1:-1;
        }
        return candidate;
    }
};

int main()
{
    Solution p1;
    vector<int> a1 = {3,2,3};
    int a = p1.majorityElement(a1);
    std::cout<< a<<std::endl;
    
}

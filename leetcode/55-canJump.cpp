#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }

int main()
{
    Solution p;
    vector<int> a = {2,3,1,1,4};
    std::cout<<p.canJump(a)<<std::endl;
}

};
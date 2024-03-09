#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int kk = k%size;
        vector<int> nums2(nums.begin(),nums.begin()+size-kk);
       
        for(int i = 0;i < kk;i++)
        {
            nums[i] = nums[size + i - kk];
        }

        for(int i = kk;i<size;i++)
        {
            nums[i] = nums2[i - kk];
        }
        return;
    }

    
};

int main()
{
    Solution p;
    vector<int> a = {1,2,3,4,5,6,7};
    p.rotate(a,3);
    for(auto it = a.begin(); it != a.end();++it)
    {
        std::cout<<*it<<std::endl;
    }
}
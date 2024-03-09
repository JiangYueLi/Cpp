#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int left = 1;
        int right = 1;
        int size = nums.size();
        int nowmax = nums[0];
        while(right < size)
        {
            if(nums[right] > nowmax)
            {   
                nowmax = nums[right];
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        return left;
    }
};

int main()
{
    Solution p1;
    vector<int> a1 = {0,0,1,1,1,2,2,3,3,4};
    p1.removeDuplicates(a1);
    for(auto it = a1.begin(); it != a1.end(); it++)
    {
        std::cout<< *it<<std::endl;
    }
    
}
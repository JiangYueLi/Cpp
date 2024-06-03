#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size();
        while(left < right)
        {
            if(nums[left] == val)
            {
                nums[left] = nums[right -1];
                right--;
            }
            else{
                left++;
            }
        }
        return left;
    }
};
int main()
{
    Solution p;
    int c = 5;
    vector<int> a= {0,1,2,2,3,0,4,2};
    int b = p.removeElement(a,2);
    for(auto it = a.begin(); it != a.end();++it)
    {
        std::cout<< *it <<std::endl;
    }
    
}
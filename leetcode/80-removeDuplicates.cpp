#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size <= 2)
        {
            return size;
        }
        int slow =2,fast = 2;
        while(fast <size)
        {
            if (nums[slow-2] != nums[fast])
            {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        
        }
        return slow;
    }
};

int main()
{
    Solution p1;
    vector<int> a1 = {1,1,1,2,2,3};
    p1.removeDuplicates(a1);
    for(auto it = a1.begin(); it != a1.end(); it++)
    {
        std::cout<< *it<<std::endl;
    }
    
}

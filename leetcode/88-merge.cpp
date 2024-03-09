#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while(m > 0 || n >0 )
        {
            if(n == 0)
            {
                return;
            }
            if(m > 0 && nums1[m -1] > nums2[n - 1])
            {
                nums1[m + n - 1] = nums1[m-1];
                m--;
            }
            else{
                nums1[m + n -1] = nums2[n-1];
                n--;
            }
        }
    }
};


int main()
{
    Solution p1;
    vector<int> a1 = {1,2,3,0,0,0};
    vector<int> a2 = {2,5,6};
    p1.merge(a1,3,a2,3);
    for(auto it = a1.begin(); it != a1.end(); it++)
    {
        std::cout<< *it<<std::endl;
    }
    
}
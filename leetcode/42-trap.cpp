#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int res = 0;
        int maxHeight = 0;
        int maxHeightIndex = 0;

        for(int i =0;i<size;i++)
        {
            if(height[i] > maxHeight)
            {
                maxHeight = height[i];
                maxHeightIndex = i;
            }
        }

        int nowmaxheight = 0;
        for(int i =0;i<=maxHeightIndex;i++)
        {
            if(height[i]>nowmaxheight)
            {
                nowmaxheight = height[i];
            }
            else
            {
                res +=nowmaxheight-height[i];
            }
        }

        nowmaxheight = 0;
        for(int i = size-1;i>=maxHeightIndex;i--)
        {
            if(height[i]>nowmaxheight)
            {
                nowmaxheight = height[i];
            }
            else
            {
                res +=nowmaxheight-height[i];
            }
        }
        return res;
    }
};

int main()
{
    Solution p ;
    vector<int> a = {4,2,0,3,2,5};
    cout<<p.trap(a)<<endl;
}
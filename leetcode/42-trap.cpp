#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
//        int size = height.size();
//        int res = 0;
//        int maxheight = 0;
//        int maxheightIndex = 0;
//        for(int i =0;i<size;i++)
//        {
//            if(height[i]> maxheight)
//            {
//                maxheight = height[i];
//                maxheightIndex = i;
//            }
//        }
//
//        int nowmaxH = 0;
//
//        for(int i =0;i<=maxheightIndex;i++)
//        {
//            if(height[i]>nowmaxH)
//            {
//                nowmaxH = height[i];
//            }
//            else
//            {
//                res += nowmaxH - height[i];
//            }
//        }
//
//        nowmaxH = 0;
//        for(int i = size -1;i>=maxheightIndex;i--)
//        {
//            if(height[i]>nowmaxH)
//            {
//                nowmaxH = height[i];
//            }
//            else
//            {
//                res += nowmaxH - height[i];
//            }
//        }
//
//        return res;
        int size = height.size();
        int res = 0;
        int maxheight = 0;
        int maxheightindedx = 0;
        for (int i = 0;i<size;i++)
        {
            if(height[i]>maxheight)
            {
                maxheight = height[i];
                maxheightindedx = i;
            }
        }
        int nowmaxheight = 0;
        for (int i = 0;i<=maxheightindedx;i++)
        {
            if(height[i]>nowmaxheight)
            {
                nowmaxheight = height[i];
            } else
            {
                res += nowmaxheight - height[i];
            }
        }
        nowmaxheight = 0;

        for (int i = size-1;i>=maxheightindedx;i--)
        {
            if(height[i]>nowmaxheight)
            {
                nowmaxheight = height[i];
            } else
            {
                res += nowmaxheight - height[i];
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
//
// Created by Y on 2023/9/7.
//
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int start = -1;
        int end = -1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                start = mid;
                end = mid;
                while(start>0 && nums[start-1] == target) start--;
                while(end<nums.size()-1 && nums[end+1] == target) end++;
                break;
            }
            else if (nums[mid] <target) left = mid+1;
            else right = mid -1;
        }
        return {start,end};
    }
};
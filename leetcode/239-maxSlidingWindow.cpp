//
// Created by Y on 2024/3/3.
//

//给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
//
//返回 滑动窗口中的最大值 。
//
//
//
//示例 1：
//
//输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
//输出：[3,3,5,5,6,7]
//解释：
//滑动窗口的位置                最大值
//---------------               -----
//[1  3  -1] -3  5  3  6  7       3
//1 [3  -1  -3] 5  3  6  7       3
//1  3 [-1  -3  5] 3  6  7       5
//1  3  -1 [-3  5  3] 6  7       5
//1  3  -1  -3 [5  3  6] 7       6
//1  3  -1  -3  5 [3  6  7]      7
//示例 2：
//
//输入：nums = [1], k = 1
//输出：[1]
#include <vector>
#include <deque>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> deque;
        for(int j =0,i = 1-k;j<nums.size();i++,j++)
        {
            if(i>0 && deque.front()==nums[i-1])
            {
                deque.pop_front();
            }
            while(!deque.empty()&& deque.back()<nums[j])
            {
                deque.pop_back();
            }
            deque.push_back(nums[j]);
            if(i>=0)
            {
                res.push_back(deque.front());
            }
        }
        return res;
    }
};
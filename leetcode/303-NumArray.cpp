//
// Created by Y on 2024/3/18.
//
#include <vector>

using namespace std;
class NumArray {
public:
    vector<int> sum;
    NumArray(vector<int>& nums) {
        int nowsum = 0;
        for(auto num:nums)
        {
            nowsum +=num;
            sum.emplace_back(nowsum);
        }
    }

    int sumRange(int left, int right) {
        if(left == 0)
        {
            return sum[right];
        }

        return sum[right] - sum[left-1];

    }
};

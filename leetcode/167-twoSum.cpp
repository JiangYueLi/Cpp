//
// Created by huyihang on 2024/3/7.
//
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        int sum = 0;
        while (i<j)
        {
            sum = numbers[i]+numbers[j];
            if(sum == target)
            {
                return vector<int>{i,j};
            } else if (sum>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return vector<int>{-1,-1};
    }
};
//
// Created by Y on 2024/3/10.
//
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ranges::sort(happiness, greater<>());
        long long result = 0;
        for(int i =0;i<k && happiness[i]>i;i++)
        {
            result +=happiness[i] -i;
        }
        return result;
    }
};
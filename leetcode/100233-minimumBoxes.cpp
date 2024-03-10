//
// Created by Y on 2024/3/10.
//
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<>);
        int capsum = 0;
        for(int i = capacity.size()-1;i>=0;i--)
        {
            capsum +=capacity[i];
            if(capsum>=sum)
            {
                return capacity.size()-i;
            }
        }
        return capacity.size();
    }
};
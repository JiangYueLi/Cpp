#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int length = gas.size();
        int res = 0, run = 0, start = 0;
        for (int i = 0; i < length; i++)
        {
            run += gas[i] - cost[i];
            res += gas[i] - cost[i];
            if (run < 0)
            {
                start = i + 1;
                run = 0;
            }
        }
        return res < 0 ? -1 : start;
    }
};
//
// Created by Y on 2024/3/15.
//

#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {

        int to_max = 0;
        for (const auto& trip: trips) {
            to_max = max(to_max, trip[2]);
        }

        unordered_map<int,int> map;
        for(auto &trip:trips)
        {
            map[trip[1]] +=trip[0];
            map[trip[2]] -=trip[0];
        }

        int sum = 0;
        for(int i =0;i<to_max;i++)
        {
            sum += map[i];
            if(sum>capacity)
                return false;
        }
        return true;
    }
};
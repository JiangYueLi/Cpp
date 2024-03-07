//
// Created by huyihang on 2024/3/7.
//

#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        long long cur = 0;
        vector<int> result;

        for(auto& w:word)
        {
            cur = cur * 10 + (w-'0');
            if(cur % m == 0)
            {
                result.push_back(1);
            } else
            {
                result.push_back(0);
            }
            cur = cur % m;
        }
        return result;
    }
};
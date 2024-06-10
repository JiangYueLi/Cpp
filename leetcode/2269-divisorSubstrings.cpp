//
// Created by Y on 2024/6/10.
//

#include <string>
using namespace std;
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();
        int res = 0;
        for(int i = 0;i<=n-k;i++)
        {
            int temp = stoi(s.substr(i,k));
            if(temp && num%temp == 0)
            {
                res++;
            }
        }
        return res;
    }
};
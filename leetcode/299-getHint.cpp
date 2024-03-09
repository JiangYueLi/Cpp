//
// Created by Y on 2024/3/10.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int A = 0;
        int B = 0;
        unordered_map<char,int> se;
        unordered_map<char,int> gu;
        for(int i =0;i<=secret.length()-1;i++)
        {
            if(secret[i] == guess[i])
            {
                A++;
            }else
            {
                se[secret[i]]++;
                gu[guess[i]]++;
            }
        }
        for(auto &s:se)
        {
            B +=min(s.second,gu[s.first]);
        }
        string res;
        res = to_string(A)+"A"+ to_string(B)+"B";
        return res;
    }
};
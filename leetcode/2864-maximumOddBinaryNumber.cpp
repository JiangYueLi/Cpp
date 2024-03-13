//
// Created by Y on 2024/3/13.
//

#include <iostream>

using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n0= 0;
        int n1 = 0;
        for(auto &ss:s)
        {
            if(ss == '0')
            {
                n0++;
            }

            if(ss == '1')
            {
                n1++;
            }
        }

        return string(n1-1,'1')+string(n0,'0')+'1';
    }
};
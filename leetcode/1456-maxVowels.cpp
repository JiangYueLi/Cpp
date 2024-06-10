//
// Created by Y on 2024/6/10.
//

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int length = s.length();

        int count = 0;
        for(int i = 0;i<k;i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
        }
        int res = count;
        for(int i = k;i<length;i++)
        {
            if(s[i-k] == 'a' || s[i-k] == 'e' || s[i-k] == 'i'|| s[i-k] == 'o' || s[i-k] == 'u')
            {
                count--;
            }

            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                count++;
            }
            res = max(count,res);
        }
        return res;
    }
};
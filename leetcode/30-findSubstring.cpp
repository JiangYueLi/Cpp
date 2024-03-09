//
// Created by Y on 2023/9/6.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int slen =s.size(),m = words.size(),n=words[0].length();
        for(int i = 0;i<n&&i+m*n<=slen;i++)
        {
            unordered_map<string,int> diff;
            for (int j = 0; j < m; j++) {
                ++diff[s.substr(i+j*n,n)];
            }

            for(auto word:words)
            {
                diff[word]--;
                if(diff[word]==0)
                {
                    diff.erase(word);
                }
            }

            for(int start = i;start<slen-m*n+1;start+=n)
            {
                if(start!=i)
                {
                    string word = s.substr(start+(m-1)*n,n);
                    diff[word]++;

                    if(diff[word]==0)
                    {
                        diff.erase(word);
                    }
                    word = s.substr(start-n,n);
                    diff[word]--;
                    if(diff[word]==0)
                    {
                        diff.erase(word);
                    }
                }

                if(diff.empty()){
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};
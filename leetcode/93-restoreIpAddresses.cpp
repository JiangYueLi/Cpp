//
// Created by Y on 2024/3/18.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if(s.size()< 4 || s.size()>12) return result;
        dfs(s,0,0);
        return result;
    }

    void dfs(string& s,int startIndex, int pointNum)
    {
        if(pointNum ==3) {
            if(isValid(s,startIndex,s.size()-1))
            {
                result.push_back(s);
            }
            return;
        }

        for(int i =startIndex;i<s.length();i++) {
            if(isValid(s,startIndex,i)) {
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                dfs(s,i+2,pointNum);
                pointNum--;
                s.erase(s.begin()+i+1);
            } else {
                break;
            }
        }

    }

    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }

};
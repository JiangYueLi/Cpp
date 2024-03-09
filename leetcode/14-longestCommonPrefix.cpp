#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string Prefix = strs[0];
        int count = strs.size();
        for(int i = 1; i<count ;i++)
        {
            Prefix = longestCommonPrefix(Prefix,strs[i]);
            if(!Prefix.size())
            {
                break;
            }
        }
        return Prefix;

    }

    string longestCommonPrefix(string s,string b)
    {
        int length = min(s.size(), b.size());
        int index = 0;
        while (index < length && s[index] == b[index]) {
            ++index;
        }
        return s.substr(0, index);
    }
};

int main()
{   
    Solution s;
    cout << "aa" << endl;
    return 0;
}
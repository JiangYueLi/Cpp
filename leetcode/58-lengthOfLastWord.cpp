#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int length = s.length();
        int last = length - 1;
        for(int i = length-1; i>=0; i--)
        {
            if(s[i]!= ' ')
            {
                last = i;
                break;
            }
        }
        int first = 0;
        for(int i = last; i>=0; i--)
        {
            if(s[i] == ' ')
            {
                first = i + 1;
                break;
            }
        }
        res = last - first + 1;
        return res;
    }
};

int main()
{
    Solution s;
    string p = "Hello World";
    cout<<s.lengthOfLastWord(p)<<endl;
}
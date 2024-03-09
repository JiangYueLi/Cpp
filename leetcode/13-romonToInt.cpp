#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<char,int> m = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
public:
    int romanToInt(string s) 
    {
        int ans = 0;
        int n = s.length();
        for(int i = 0;i<n;i++)
        {
            int value = m[s[i]];
            if(i< n-1 && value < m[s[i+1]])
            {
                ans -=value;
            }
            else
            {
                ans +=value;
            }
        }
        return ans;
    }


};

int main()
{   
    Solution s;
    cout << s.romanToInt("IV") << endl;
    return 0;
}
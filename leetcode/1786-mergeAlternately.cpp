
#include <iostream>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int index = 0;
        while(index < word1.length() || index < word2.length())
        {
            if(index < word1.length())
            {
                s += word1[index]; 
            }

            if(index < word2.length())
            {
                s += word2[index]; 
            }
            index++;
        }
        
        return s;
    }
};

int main()
{
    Solution p;
    string a = "121";
    string b = "qwe";
    std::cout<< p.mergeAlternately(a,b)<<std::endl;
}
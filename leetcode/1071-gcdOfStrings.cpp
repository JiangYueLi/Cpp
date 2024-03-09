#include<iostream>
using namespace std;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {

        int l1 = str1.length();
        int l2 = str2.length();

        for(int i = min(l1,l2);i>0;i--)
        {
            if(l1 % i != 0 || l2 % i != 0)
            {
                continue;
            }

            string tar = str1.substr(0,i);
            if(check(tar,str1) && check(tar,str2))
            {
                return tar;
            }
        }

        return "";

    }

    bool check(string s, string b)
    {
        if(b.length() % s.length() != 0)
        {
            return false;
        }

        string t = "";
        for(int i =0;i < b.length()/s.length();i++)
        {
            t += s;
        }

        if(t == b)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Solution p;
    string a = "abcabc";
    string b = "abc";
    std::cout<<p.gcdOfStrings(b,a)<<std::endl;
    
    std::cout<<a.substr(0,4)<<std::endl;
}
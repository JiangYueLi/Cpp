//
// Created by Y on 2023/9/5.
//
#include<iostream>

using namespace std;
class Solution {
public:
    int minimumOperations(string num) {
        int res0 = 0;
        int res5 = 0;
        int n = num.length()-1;
        if(n == 0) return num[0]=='0'?0:1;
        while(n>=0 && num[n]!='0')
        {
            res0++;
            n--;
        }
        if(n>0)
        {
            n--;
            while(n>0 && num[n]!='0'&& num[n]!='5')
            {
                n--;
                res0++;
            }
            if(n==0&&num[n]!='0'&&num[n]!='5')
            {
                res0++;
            }
        }

        int m = num.length()-1;
        while(m>=0 && num[m]!='5')
        {
            res5++;
            m--;
        }
        if(m==0)
        {
            res5++;
        }
        if(m>0)
        {
            m--;
            while(m>0 && num[m]!='2'&& num[m]!='7')
            {
                m--;
                res5++;
            }
            if(m==0&&num[m]!='2'&&num[m]!='7')
            {
                res5 +=2;
            }
        }

        return min(res0,res5);
    }
};

int main()
{
    Solution s;
    int n = s.minimumOperations("51");
    cout<<n<<endl;
}
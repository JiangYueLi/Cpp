#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int length = ratings.size();
        vector<int> res(length,1);
        for(int i =1;i<length;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                res[i] = res[i-1] + 1;
            }
        }

        for(int i = length -2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                res[i] = max(res[i],res[i+1]+1);
            }
        }
        int re = 0;
        for(auto r: res)
        {
            re +=r; 
        }
        return re;
    }
};

int main()
{
    Solution p;
    vector<int> a = {1,0,2};
    cout<<p.candy(a)<<endl;
}
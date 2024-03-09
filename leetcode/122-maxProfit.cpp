#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int Profit = 0;
       int nowPrice = 0;
       bool havePrice = false;
       for(int i =0;i<prices.size()-1;i++)
       {    
            if(havePrice && prices[i]>=nowPrice)
            {
                Profit += prices[i] - nowPrice;
                havePrice = false;
                nowPrice = 0;
            }

            if(prices[i+1] >= prices[i])
            {   
                havePrice = true;
                nowPrice = prices[i];
            }
       }
       if(havePrice && prices[prices.size()-1]>=nowPrice)
       {
            Profit += prices[prices.size()-1] - nowPrice;
       }
       return Profit; 
    }
};

int main()
{
    Solution p;
    vector<int> a = {7,1,5,3,6,4};
    std::cout<<p.maxProfit(a)<<std::endl;
}
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 1)
        {
            return 0;
        }
        int Profit = 0;
        int MinPrice = prices[0];
        for(int i = 1;i<size;i++)
        {
            if(prices[i]<MinPrice)
            {
                MinPrice = prices[i];
                continue;
            }

            if (prices[i] - MinPrice > Profit)
            {
                Profit = prices[i] - MinPrice;
            }
            
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
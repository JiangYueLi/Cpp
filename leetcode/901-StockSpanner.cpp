#include<iostream>
#include<stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> stack;
    int idx;
    StockSpanner() {
        this->stack.emplace(INT_MAX,-1);
        this->idx = -1;
    }
    
    int next(int price) {
        idx ++;
        while(price>=stack.top().first)
        {
            stack.pop();
        }

        int ret = idx - stack.top().second;
        stack.emplace(price,idx);
        return ret;
    }
};
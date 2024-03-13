//
// Created by Y on 2024/3/13.
//

#include <queue>
using namespace std;
class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> queue;
        for(int i =1;i<=n;i++)
        {
            queue.emplace(i);
        }
        while (queue.size()>1)
        {
            for(int i =1;i<k;i++)
            {
                queue.emplace(queue.front());
                queue.pop();
            }
            queue.pop();
        }
        return queue.front();
    }
};
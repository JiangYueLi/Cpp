#include <iostream>
#include <vector>
#include "leetcode/924-minMalwareSpread.cpp"
using namespace std;
int main() {
    vector<vector<int>> graph = {
            {1, 1, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1},
            {0, 0, 0, 0, 1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 1, 0, 1}
    };
    vector<int> res = {6,2,8,0,4};
    Solution s;

    std::cout << s.minMalwareSpread(graph,res) << std::endl;
    return 0;
}

#include <iostream>
#include <vector>
#include "leetcode/2605-minNumber.cpp"
using namespace std;
int main() {
    vector<int> vec1={4,6};
    vector<int> vec2={2,5,7};
    Solution s;

    std::cout << s.minNumber(vec1,vec2) << std::endl;
    return 0;
}

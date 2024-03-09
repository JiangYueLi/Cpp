#include <iostream>
#include <vector>
#include "leetcode/299-getHint.cpp"
using namespace std;
int main() {
    string a = "1807";
    string b = "7810";
    Solution s;

    std::cout << s.getHint(a,b) << std::endl;
    return 0;
}

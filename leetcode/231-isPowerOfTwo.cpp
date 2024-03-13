//
// Created by Y on 2024/3/13.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {

        return n>0 && (n&(n-1)) == 0;
    }
};
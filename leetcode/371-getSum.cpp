//
// Created by Y on 2024/3/13.
//

class Solution {
public:
    int getSum(int a, int b) {
        if(!a) return b;
        int sum = a ^ b, carry = (unsigned)(a & b) << 1;
        return getSum(carry, sum);
    }
};
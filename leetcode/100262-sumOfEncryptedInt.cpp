//
// Created by Y on 2024/3/16.
//

#include <iostream>

#include <vector>
using namespace std;
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += encrypt(num);
        }
        return sum;
    }


    int getMaxDigit(int num) {
        int maxDigit = 0;
        while (num > 0) {
            int digit = num % 10;
            maxDigit = std::max(maxDigit, digit);
            num /= 10;
        }
        return maxDigit;
    }

    int encrypt(int num) {
        int maxDigit = getMaxDigit(num);
        int encryptedNum = 0;
        while (num > 0) {
            encryptedNum = encryptedNum * 10 + maxDigit;
            num /= 10;
        }
        return encryptedNum;
    }
};
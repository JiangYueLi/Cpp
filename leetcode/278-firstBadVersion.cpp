//
// Created by huyihang on 2024/3/8.
//


// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int isBadVersion(int n)
    {
        return true;
    }
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        while(left<right)
        {
            int mid = left+(right-left)/2;
            if(isBadVersion(mid) == true)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};
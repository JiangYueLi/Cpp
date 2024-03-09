#include <iostream>
#include <vector>
#include <math.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), res = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 1; i <= n; i++) {
            if (citations[i-1] >= i) res = i;
        }
        return res;
    }
};
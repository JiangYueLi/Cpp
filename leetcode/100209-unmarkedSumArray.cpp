//
// Created by Y on 2024/3/16.
//


#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        long long allsum = 0;
        for (int num : nums) {
            allsum += num;
        }
        vector<bool> marked(n, false); // 用于记录元素是否被标记
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 最小堆，存储未标记的元素和它们的下标

        // 初始化优先队列，将所有未标记的元素加入
        for (int i = 0; i < n; ++i) {
            pq.emplace(nums[i], i);
        }

        vector<long long> answer;
        for (auto& query : queries) {
            int index = query[0];
            int k = query[1];

            long long sum = allsum;
            // 如果当前元素未标记，则标记它
            if (!marked[index]) {
                marked[index] = true; // 标记元素
                sum = allsum - nums[index];
            }

            // 标记 k 个最小元素（如果存在）
            while (k > 0 && !pq.empty()) {
                auto [val, idx] = pq.top();
                pq.pop();
                if (marked[idx]) {
                    continue;
                }
                marked[idx] = true;
                sum -= val; // 从和中减去已标记元素的值
                k--;
            }
            allsum = sum;
            answer.push_back(sum); // 添加结果到答案数组中
        }

        return answer;
    }
};
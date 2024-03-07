//
// Created by huyihang on 2024/3/7.
//

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;

        // 判断是否有环
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next; // 移动快指针
            slow = slow->next;       // 移动慢指针
            if (fast == slow) {      // 发现环
                break;
            }
        }

        // 如果没有环，返回 nullptr
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // 寻找环的起始节点
        slow = head;
        while (fast != slow) {
            fast = fast->next;      // 快慢指针以相同的速度移动
            slow = slow->next;
        }
        return fast; // 或 slow，因为它们在环的起点相遇
    }
};
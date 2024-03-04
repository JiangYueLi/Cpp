//
// Created by huyihang on 2024/3/4.
//


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;
        while (head)
        {
            ListNode *p = head->next;
            head->next = pre;
            pre = head;
            head = p;
        }
        return pre;
    }
};
//
// Created by Y on 2024/6/12.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }

        ListNode *one = head;
        ListNode *two = one->next;
        ListNode *three = two->next;

        two->next = one;
        one->next = swapPairs(three);
        return two;
    }
};
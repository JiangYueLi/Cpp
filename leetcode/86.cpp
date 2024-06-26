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
    ListNode* partition(ListNode* head, int x) {
//        ListNode* small = new ListNode(0);
//        ListNode* smallHead = small;
//        ListNode* large = new ListNode(0);
//        ListNode* largeHead = large;
//        while (head != nullptr) {
//            if (head->val < x) {
//                small->next = head;
//                small = small->next;
//            } else {
//                large->next = head;
//                large = large->next;
//            }
//            head = head->next;
//        }
//        large->next = nullptr;
//        small->next = largeHead->next;
//        return smallHead->next;
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode *smallhead = small;
        ListNode *largehead = large;
        while(head)
        {
            if(head->val<x)
            {
                small->next = head;
                small = small->next;
            }
            else
            {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largehead->next;
        return smallhead->next;
    }
};
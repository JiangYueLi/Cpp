//
// Created by Y on 2023/9/12.
//
#include <iostream>
 struct ListNode {
     int val;
     ListNode *next;

     ListNode() : val(0), next(nullptr) {}

     ListNode(int x) : val(x), next(nullptr) {}

     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dum = new ListNode(-1);
        dum->next = head;
        ListNode *pre = dum;
        while(true)
        {
            ListNode *last = pre;
            for(int i = 0;i<k;i++)
            {
                last = last->next;
                if(last == nullptr)
                {
                    return dum->next;
                }
            }

            ListNode *cur = pre->next;
            for(int i =0;i<k-1;i++)
            {
                ListNode *next = cur->next;
                cur->next = next->next;
                next->next = pre->next;
                pre->next = next;
            }
            pre = cur;
        }
    }
};
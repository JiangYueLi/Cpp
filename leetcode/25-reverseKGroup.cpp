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
        ListNode *dump = new ListNode(-1);
        dump->next = head;
        ListNode *pre = dump;
        while (true)
        {
            ListNode *last = pre;
            for(int i =0;i<k;i++)
            {
                last = last->next;
                if(last == nullptr)
                {
                    return dump->next;
                }
            }

            ListNode *cur = pre->next;
            for(int i=0;i<k-1;i++)
            {
                ListNode *next = cur->next;    //2
                cur->next =next->next;    //头连下一组
                next->next = pre->next; // 2-》1；
                pre->next = next;    //0-2》
            }
            pre = cur;
        }
    }
};
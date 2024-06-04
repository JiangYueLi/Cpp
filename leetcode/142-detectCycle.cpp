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
       ListNode *a = head;
       ListNode *b = head;

       while(b != nullptr && b->next != nullptr)
       {
           a = a->next;
           b = b->next->next;

           if(a==b)
           {
               break;
           }
       }

       if(b == nullptr || b->next == nullptr)
       {
           return a;
       }

       ListNode *c= head;

       while(c != a)
       {
           c = c->next;
           a = a->next;
       }
        return a;
    }
};
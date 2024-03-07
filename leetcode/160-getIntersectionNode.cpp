//
// Created by huyihang on 2024/3/7.
//

#include <iostream>

using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA== nullptr || headB == nullptr)
        {
            return nullptr;
        }
        ListNode *PA =headA;
        ListNode *PB = headB;
        while (PA!=PB)
        {
            PA = PA== nullptr?headB:PA->next;
            PB = PB== nullptr?headA:PB->next;
        }
        return PA;
    }
};
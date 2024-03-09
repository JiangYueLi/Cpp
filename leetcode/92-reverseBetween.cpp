//
// Created by Y on 2023/9/12.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dum = new ListNode(-1);
        dum->next = head;
        ListNode *ll = dum;
        for(int i =0;i<left-1;i++)
        {
            ll =ll->next;
        }
        ListNode *l = ll->next;

        for(int i=0;i<right-left;i++)
        {
            ListNode *next = l->next;
            l->next = next->next;
            next->next = ll->next;
            ll->next = next;
        }


        return dum->next;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = new ListNode();

        while(head)
        {
            ListNode *p = head->next;
            head->next =pre;
            pre = head;
            head = p;
        }
        return pre;
    }
};
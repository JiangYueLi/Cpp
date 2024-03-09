//
// Created by Y on 2023/9/13.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size = 0;
        ListNode *listsize = head;
        while(listsize!= nullptr)
        {
            listsize = listsize->next;
            size ++;
        }

        ListNode *dum = new ListNode(-1);
        dum->next = head;
        ListNode *cur = dum;
        for(int i = 0;i<size-n;i++)
        {
            cur = cur->next;
        }
        ListNode *next = cur->next;
        cur->next = next->next;
        return dum->next;
    }
};
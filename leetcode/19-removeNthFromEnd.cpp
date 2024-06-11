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

        ListNode *dum = new ListNode(0);
        dum->next = head;

        ListNode *fast = dum;

        for(int i = 0;i<n;i++)
        {
            fast = fast->next;
        }
        ListNode *slow = dum;
        while(fast != nullptr && fast->next!= nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = temp->next;
        temp->next = nullptr;
        return dum->next;
    }
};
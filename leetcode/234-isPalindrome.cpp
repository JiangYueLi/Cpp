//
// Created by Y on 2023/9/12.
//
#include <iostream>
#include <vector>
#include<algorithm>
#include <stack>

using namespace std;
struct ListNode{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> res;
        ListNode *cur = head;
        while (cur!= nullptr)
        {
            res.emplace_back(cur->val);
            cur = cur->next;
        }

        for(int i =0,j = res.size()-1;i<j;i++,j--)
        {
            if(res[i] != res[j]) return false;
        }
        return true;
    }
};
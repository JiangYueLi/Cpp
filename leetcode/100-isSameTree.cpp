//
// Created by huyihang on 2023/9/6.
//
#include <iostream>

using namespace std;
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)
        {
            return true;
        }
        if(p!=NULL && q!=NULL)
        {
            if(p->val==q->val)
            {
                return isSameTree(p->left,q->left)&& isSameTree(p->right,q->right);
            }
        }

        return false;
    }
};
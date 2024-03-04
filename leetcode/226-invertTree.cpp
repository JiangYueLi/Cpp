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

    TreeNode* invertTree(TreeNode* root) {
        if(root== NULL)
        {
            return root;
        }
        invert(root);
        return root;
    }

    void invert(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }

        TreeNode* t = root->left;
        root->left = root->right;
        root->right = t;
        invert(root->left);
        invert(root->right);
    }

};
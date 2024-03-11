//
// Created by huyihang on 2024/3/11.
//



struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return true;
        return recur(root->left,root->right);
    }
    bool recur(TreeNode* left,TreeNode * right)
    {
        if(left == nullptr && right== nullptr) return true;
        if(left == nullptr || right == nullptr || left->val != right->val) return false;
        return recur(left->left,right->right) && recur(left->right,right->left);
    }
};
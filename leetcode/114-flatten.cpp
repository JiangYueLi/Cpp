//
// Created by Y on 2023/9/13.
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
    TreeNode *last = nullptr;
    void flatten(TreeNode* root) {
        if(root == nullptr)
        {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;
        last = root;

    }
};
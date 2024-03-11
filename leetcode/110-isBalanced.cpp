//
// Created by huyihang on 2024/3/11.
//

#include <algorithm>

using namespace std;
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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int deepL = getdeep(root->left);
        int deepR = getdeep(root->right);
        if(abs(deepL-deepR)>1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getdeep(TreeNode *root)
    {
        if(root == nullptr) return 0;
        return max(getdeep(root->right), getdeep(root->left))+1;
    }
};
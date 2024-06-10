//
// Created by Y on 2024/6/10.
//

#include <vector>

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        res = max(check(root),max(check(root->left), check(root->right)));
        return res;
    }

    int maxdeep(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        return max(maxdeep(root->left), maxdeep(root->right))+1;
    }
    int check(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        return max(maxdeep(root->right)+ maxdeep(root->left),max(check(root->left), check(root->right)));
    }
};
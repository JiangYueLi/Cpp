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

    int maxDepth(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        int deepL = height(root->left);
        int deepR = height(root->right);
        return max(deepL,deepR)+1;
    }
    int height(TreeNode* &root){
        if(root == nullptr) return 0;
        return max(height(root->left) , height(root->right)) + 1;
    }
};
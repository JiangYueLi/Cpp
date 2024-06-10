//
// Created by Y on 2024/6/10.
//
#include <vector>
#include <cstdlib>

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
    bool isValidBST(TreeNode* root) {

        return help(root,LONG_MIN,LONG_MAX);

    }

    bool help(TreeNode* root,long long lower,long long up)
    {
        if(root == nullptr)
        {
            return true;
        }

        if(root->val<=lower || root->val>=up)
        {
            return false;
        }

        return help(root->left,lower,root->val) && help(root->right,root->val,up);
    }

};
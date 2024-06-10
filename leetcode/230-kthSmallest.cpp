//
// Created by huyihang on 2024/3/8.
//

#include <iostream>
#include <queue>

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
    int kthSmallest(TreeNode* root, int k) {
        //中序遍历
        vector<int> result;
        dfs(root,result);
        return result[k-1];
    }

    void dfs(TreeNode* root,vector<int>& res)
    {
        if(!root) return;
        dfs(root->left,res);
        res.push_back(root->val);
        dfs(root->right,res);
    }
};
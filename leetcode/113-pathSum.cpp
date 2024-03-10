//
// Created by Huyihang on 2024/3/11.
//

#include <vector>
#include <altivec.h>

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
    vector<int> path;
    vector<vector<int>> ret;
    void dfs(TreeNode *root,int targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        path.emplace_back(root->val);
        targetSum -=root->val;
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            ret.emplace_back(path);
        }
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ret;
    }


};
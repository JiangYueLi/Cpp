//
// Created by huyihang on 2024/3/12.
//

#include <unordered_set>

using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements {
public:
    unordered_set<int> s;
    void dfs(TreeNode* root)
    {
        if(root== nullptr)
        {
            return;
        }
        s.insert(root->val);
        if(root->left)
        {
            root->left->val = 2*root->val +1;
            dfs(root->left);
        }
        if(root->right)
        {
            root->right->val = 2*root->val+2;
            dfs(root->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val = 0;
       dfs(root);
    }

    bool find(int target) {
        return s.count(target)>0;
    }
};
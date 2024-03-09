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

#include <vector>
#include <unordered_map>

using namespace std;
class Solution {
public:
    unordered_map<int,int> index;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return MyBuild(inorder,postorder,0,n-1,0,n-1);
    }

    TreeNode* MyBuild(vector<int>& inorder, vector<int>& postorder,int in_left,int in_right,int post_left,int post_right)
    {
        if(in_left>in_right)
        {
            return nullptr;
        }

        int root_val = postorder[post_right];

        int in_root = index[root_val];

        TreeNode* root = new TreeNode(root_val);
        int size_left_subtree = in_root - in_left;
        root->left = MyBuild(inorder,postorder,in_left,in_root-1,post_left,post_left+size_left_subtree-1);
        root->right = MyBuild(inorder,postorder,in_root+1,in_right,post_left+size_left_subtree,post_right-1);
        return root;
    }
};
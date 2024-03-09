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
    unordered_map<int,int> inded;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for (int i = 0; i < n; ++i) {
            inded[inorder[i]] = i;
        }
        return MyBuildTree(preorder,inorder,0,n-1,0,n-1);
    }

    TreeNode* MyBuildTree(vector<int>& preorder,vector<int>& inorder,int prestart,int preend,int instart,int inend)
    {
        if(prestart>preend)
        {
            return nullptr;
        }
        int pre_root = prestart;
        int in_root = inded[preorder[pre_root]];
        TreeNode* root = new TreeNode(preorder[pre_root]);
        int size_left_subtree = in_root - instart;
        root->left = MyBuildTree(preorder,inorder,prestart+1,prestart+size_left_subtree,instart,in_root-1);
        root->right = MyBuildTree(preorder,inorder,prestart+size_left_subtree+1,preend,in_root+1,inend);
        return root;
    }
};
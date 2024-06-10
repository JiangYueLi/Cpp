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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums,0,nums.size()-1);
    }

    TreeNode* buildTree(vector<int> &nums,int l,int r)
    {
        if(l > r)
        {
            return nullptr;
        }
        int m = l+(r-l)/2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildTree(nums,l,m-1);
        root->right = buildTree(nums,m+1,r);
        return root;
    }

};
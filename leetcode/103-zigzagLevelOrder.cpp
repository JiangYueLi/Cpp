//
// Created by huyihang on 2024/3/8.
//
#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
        {
            return res;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        int flag = 1;
        while (!queue.empty())
        {
            int size = queue.size();
            res.push_back(vector<int>());
            for(int i = 0;i<size;i++)
            {
                TreeNode* node = queue.front(); queue.pop();
                res.back().push_back(node->val);
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);

            }
            if(flag ==-1)
            {
                reverse(res.back().begin(),res.back().end());
            }
            flag = -flag;
        }
        return res;
    }
};
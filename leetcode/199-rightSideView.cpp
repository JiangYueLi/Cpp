//
// Created by Y on 2024/6/11.
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
    vector<int> rightSideView(TreeNode* root) {
        if(root ==nullptr)
        {
            return {};
        }
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if(tmp->left !=nullptr)
                {
                    q.push(tmp->left);
                }
                if(tmp->right !=nullptr)
                {
                    q.push(tmp->right);
                }
                if(i == n-1) res.push_back(tmp->val);
            }
        }
        return res;
    }


};
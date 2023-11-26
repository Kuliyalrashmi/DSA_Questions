/*
Leetcode Question No 103 Binary Tree Zigzag Level Order Traversal
Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        bool flag=1;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++)
            {
                TreeNode*node=q.front();
                q.pop();
                if(flag==1)
                {
                    temp[i]=node->val;
                }
                else
                {
                    temp[n-i-1]=node->val;
                }
                if(node->left!=NULL)
                {
                    q.push(node->left);
                }
                if(node->right!=NULL)
                {
                    q.push(node->right);
                }
            }
            flag=!flag;
            ans.push_back(temp);
        }
        return ans;
    }
};

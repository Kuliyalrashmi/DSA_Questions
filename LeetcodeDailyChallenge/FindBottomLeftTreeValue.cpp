/* 28-Feb-2024
Leetcode Question no 513 Find Bottom Left Tree Value
Given the root of a binary tree, 
return the leftmost value in the last row of the tree.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
          int n=q.size();
          for(int i=0;i<n;i++)
          {
            TreeNode*front=q.front();
            q.pop();
             if(i==0)
             {
                ans=front->val;
             }
            if(front->left!=NULL)
            {
                q.push(front->left);
            }
            if(front->right!=NULL)
            {
                q.push(front->right);
            }
          }
        }
        return ans;
    }
};

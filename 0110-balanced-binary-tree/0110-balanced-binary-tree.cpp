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
    int solve(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=solve(root->left);
        int right=solve(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        if(!isBalanced(root->left))
        {
            return false;
        }
        if(!isBalanced(root->right))
        {
            return false;
        }
        int lh=solve(root->left);
        int rh=solve(root->right);
        if(abs(lh-rh)<=1)
        {
            return true;
        }
        return false;
    }
};
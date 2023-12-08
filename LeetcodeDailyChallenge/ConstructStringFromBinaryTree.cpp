/* 8-Dec-2023
Leetcode Question no 606 Construct String From Binary Tree
Given the root of a binary tree, construct a string consisting of parenthesis and integers
from a binary tree with the preorder traversal way, and return it.
Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship
between the string and the original binary tree.
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
    void preorderTraversal(TreeNode*root,string &ans)
    {
        if(root==NULL)
        {
            return;
        }
        ans+=to_string(root->val);
        if(root->left)
        {
            ans+="(";
            preorderTraversal(root->left,ans);
            ans+=")";
        }
        if(root->right)
        {
            if(root->left==NULL)
            {
                ans+="()";
            }
            ans+="(";
            preorderTraversal(root->right,ans);
            ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        string ans="";
        preorderTraversal(root,ans);
        return ans;
    }
};

/* 
Leetcode Question no 124 Binary Tree Maximum Path Sum
A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them
A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
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
    int solve(TreeNode*root,int& path)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left=max(0,solve(root->left,path));
        int right=max(0,solve(root->right,path));
        path=max(path,left+right+root->val);
        return max (left,right)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int path=INT_MIN;
        solve(root,path);
        return path;
    }
};

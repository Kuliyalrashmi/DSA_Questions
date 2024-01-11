/* 
      11-JAn-2024
Leetcode Question no 1026 Maximum Difference between Node and Ancestor
Given the root of a binary tree, find the maximum value v for which there exist different nodes a and b 
where v = |a.val - b.val| and a is an ancestor of b.

A node a is an ancestor of b if either: any child of a is equal to b or any child of a is an ancestor of b.

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
    int solve(TreeNode*root,int value1,int value2)
    {
        if(root==NULL)
        {
            return abs(value1-value2);
        }
        value1=min(root->val,value1);
        value2=max(root->val,value2);

        int left=solve(root->left,value1,value2);
        int right=solve(root->right,value1,value2);
        return max(left,right);
    }
    int maxAncestorDiff(TreeNode* root) {
        int value1=root->val,value2=root->val;
        return solve(root,value1,value2);
    }
};

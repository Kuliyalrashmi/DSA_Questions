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
    int solve(TreeNode* root,int x,int &l,int &r)
    {
        if(!root)
        {
            return 0;
        }
        int left=solve(root->left,x,l,r);
        int right=solve(root->right,x,l,r);
        if(root->val==x)
        {
            l=left;
            r=right;
        }
        return left+right+1;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        int l=0,r=0;
        solve(root,x,l,r);
        int value=n-(l+r+1);
        int node=max(value,max(l,r));
        if(node>n/2)
        {
            return true;
        }
        return false;
        
    }
};
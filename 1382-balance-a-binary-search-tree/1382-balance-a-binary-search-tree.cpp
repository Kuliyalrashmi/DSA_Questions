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
    TreeNode* solve(int start,int end,vector<int>&nums)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=start+(end-start)/2;
        TreeNode*root=new TreeNode(nums[mid]);
        root->left=solve(start,mid-1,nums);
        root->right=solve(mid+1,end,nums);
        return root;
    }
    void inorder(TreeNode* root,vector<int>&temp)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
        return solve(0,temp.size()-1,temp);
    }
};
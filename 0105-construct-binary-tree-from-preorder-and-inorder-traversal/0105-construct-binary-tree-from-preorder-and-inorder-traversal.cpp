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
    TreeNode*creation(int inStart,int inEnd,vector<int>&inorder,int preStart,int preEnd,vector<int>&preorder,map<int,int>&mp)
    {
        if(preStart>preEnd||inStart>inEnd)
        {
            return NULL;
        }
        TreeNode*root=new TreeNode(preorder[preStart]);
        int mid=mp[root->val];
        int start=mid-inStart;
        root->left=creation(inStart,mid-1,inorder,preStart+1,preStart+start,preorder,mp);
        root->right=creation(mid+1,inEnd,inorder,preStart+start+1,preEnd,preorder,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inStart=0,inEnd=inorder.size()-1,preStart=0,preEnd=preorder.size()-1;
        map<int,int>mp;
        for(int i=inStart;i<=inEnd;i++)
        {
            mp[inorder[i]]=i;
        }
        return creation(inStart,inEnd,inorder,preStart,preEnd,preorder,mp);
    }
};
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
    void inorder(TreeNode* root,int k,int& count,int &mini)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,k,count,mini);
        count++;
        if(count==k)
        {
            mini=root->val;
            return;
        }
        inorder(root->right,k,count,mini);
    }
    int kthSmallest(TreeNode* root, int k) {
        int Kth_small=-1,count=0;
        inorder(root,k,count,Kth_small);
        return Kth_small;
    }
};
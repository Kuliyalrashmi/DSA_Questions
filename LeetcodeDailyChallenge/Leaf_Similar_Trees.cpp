/*   9-Jan-2024
  
Leetcode Question no 872 Leaf-Similar Trees

Consider all the leaves of a binary tree, from left to right order,
the values of those leaves form a leaf value sequence.

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
    void leafNodes(TreeNode*root,vector<int>&temp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            temp.push_back(root->val);
        }
        leafNodes(root->left,temp);
        leafNodes(root->right,temp);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>temp1,temp2;
        leafNodes(root1,temp1);
        leafNodes(root2,temp2);
        return temp1==temp2;
    }
};

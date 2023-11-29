/* Leetcode Question no 101 Symmetric tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
    bool mirrorImage(TreeNode*leftchild,TreeNode*rightchild)
    {
        if(leftchild==NULL&&rightchild==NULL)
        {
            return true;
        }
        else if(leftchild==NULL || rightchild==NULL)
        {
            return false;
        }
        if(leftchild->val!=rightchild->val)
        {
            return false;
        }
        return mirrorImage(leftchild->left,rightchild->right)&&mirrorImage(leftchild->right,rightchild->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return NULL;
        }
        return mirrorImage(root->left,root->right);
    }
};

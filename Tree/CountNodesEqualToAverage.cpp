/* Leetcode 2265 Count Nodes Equal to Average of Subtree
Given the root of a binary tree,
return the number of nodes where the value of the node is equal to the average of the values in its subtree.
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
    pair<int,int>traverse(TreeNode*root,int &ans)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        pair<int,int>left=traverse(root->left,ans);
        pair<int,int>right=traverse(root->right,ans);
        int sum=root->val+left.first+right.first;
        int count=1+left.second+right.second;
        if(sum/count==root->val)
        {
            ans++;
        }
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        int count=0;
        traverse(root,count);
        return count;
    }
};

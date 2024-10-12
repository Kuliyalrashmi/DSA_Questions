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
    void solve(TreeNode* root,int number,int& sum)
    {
        if(!root)
        {
            return;
        }
        number=number*10+root->val;
        solve(root->left,number,sum);
        solve(root->right,number,sum);
        if(!root->left&&!root->right)
        {
            sum+=number;
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root,0,sum);
        return sum;
    }
};
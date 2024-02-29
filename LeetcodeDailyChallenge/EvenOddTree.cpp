/*29-Feb-2024
  Leetcode question no 1609 Even Odd TRee
A binary tree is named Even-Odd if it meets the following conditions:

The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=-1;
        while(!q.empty())
        {
            level++;
            int size=q.size();
            int previous;
            if(level%2==0)
            {
                previous=INT_MIN;
            }
            else
            {
                previous=INT_MAX;
            }
            for(int i=0;i<size;i++)
            {
                TreeNode*front=q.front();
                q.pop();
                int val=front->val;
                if((level%2==0&&(val%2==0||val<=previous))||
                (level%2!=0&&(val%2!=0||val>=previous)))
                {
                    return false;
                }
                previous=val;
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
        }
        return true;
    }
};

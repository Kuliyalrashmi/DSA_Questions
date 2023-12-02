/*   If the null nodes between two nodes should be counted in width of binary tree


Leetcode Question no 662 MAximum Width Of a Binary Tree
Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), 
where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        queue<pair<TreeNode* ,int>>q;
        q.push({root,0});
        int ans=0;
        while(!q.empty())
        {
            int size=q.size();
            int ind=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* curr=q.front().first;
                long long curr_id=q.front().second-ind;
                q.pop();
                if(i==0)
                {
                    first=curr_id;
                }
                if(i==size-1)
                {
                    last=curr_id;
                }
            if(curr->left!=NULL)
            {
                q.push({curr->left,curr_id*2+1});
            }
            if(curr->right!=NULL)
            {
                q.push({curr->right,curr_id*2+2});
            }
            }
        ans=max(ans,last-first+1);
        }
        return ans;
    }
};



/* 
Approach 2 
If null nodes bwtween 2 nodes are not cunted in width of Binary Tree 
*/
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    int count=0;
    if(!root)
    {
        return 0;
    }
    queue<TreeNode<int>*>q;
    q.push(root);
    while(!q.empty())
    {
        int size=q.size();
        count=max(count,size);
        for(int i=0;i<size;i++)
        {
            TreeNode<int>*curr=q.front();
            q.pop();
            if(curr->left)
            {
                q.push(curr->left);
            }
            if(curr->right)
            {
                q.push(curr->right);
            }
        }
    }
    return count;
}

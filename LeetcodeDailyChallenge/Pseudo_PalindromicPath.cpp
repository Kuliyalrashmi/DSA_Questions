/*  24-Jan-2024
Leetcode Question no 1457 Pseudo PAlindromic Path In A Binary Tree
Given a binary tree where node values are digits from 1 to 9.
  A path in the binary tree is said to be pseudo-palindromic 
  if at least one permutation of the node values in the path is a palindrome.

Return the number of pseudo-palindromic paths going from the root node to leaf nodes.
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

/* DFS Approach */
class Solution {
public:
    void solve(TreeNode* root,vector<int>&path,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        path[root->val]++;
        if(root->left==NULL&&root->right==NULL)
        {
            int odd_count=0;
            for(int i=0;i<=9;i++)
            {
                if(path[i]%2!=0)
                {
                   odd_count++;
                }
            }
            if(odd_count<=1)
            {
                ans+=1;
            }
        }
        solve(root->left,path,ans);
        solve(root->right,path,ans);
        path[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        vector<int>path(10,0);
        solve(root,path,ans);
        return ans;
    }
};



/* Bit Manipulation */
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
    void solve(TreeNode* root,int temp,int &ans)
    {
        if(root==NULL)
        {
            return;
        }
        temp=temp^(1<<root->val);
        if(root->left==NULL&&root->right==NULL)
        {
           if((temp&(temp-1))==0)
           {
               ans++;
           }
        }
        solve(root->left,temp,ans);
        solve(root->right,temp,ans);
       
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int ans=0;
        solve(root,0,ans);
        return ans;
    }
};

 

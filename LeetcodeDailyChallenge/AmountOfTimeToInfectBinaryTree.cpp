/*   10-Jan-2024
  
Leetcode Question no 2385 Amount Of Time For A Binary Tree To Be Infected
You are given the root of a binary tree with unique values, and an integer start. 
At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

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
    void build(TreeNode* root,unordered_map<int,vector<int>>&mp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            mp[root->val].push_back(root->left->val);
            mp[root->left->val].push_back(root->val);
        }
        if(root->right!=NULL)
        {
            mp[root->val].push_back(root->right->val);
            mp[root->right->val].push_back(root->val);
        }
        build(root->left,mp);
        build(root->right,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mp;
        build(root,mp);
        queue<int>q;
        q.push(start);
        unordered_set<int>visited;
        int time=-1;
        while(!q.empty())
        {
            int size=q.size();
            time++;
            for(int i=0;i<size;i++)
            {
                int curr=q.front();
                q.pop();
                visited.insert(curr);
                for(auto neighbour:mp[curr])
                {
                    if(!visited.count(neighbour))
                    {
                        q.push(neighbour);
                    }
                }
            }
        }
        return time;
    }
};

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
   void create(TreeNode*root,TreeNode*prev,unordered_set<TreeNode*>&st,unordered_map<TreeNode*,vector<TreeNode*>>&adj)
   {
       if(root==NULL)
       {
           return;
       }
       if(root->left==NULL&&root->right==NULL)
       {
           st.insert(root);
       }
       if(prev!=NULL)
       {
           adj[root].push_back(prev);
           adj[prev].push_back(root);
       }
       create(root->left,root,st,adj);
       create(root->right,root,st,adj);
   }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        unordered_set<TreeNode*>st;
        create(root,NULL,st,adj);
        int count=0;
        for(auto i:st)
        {
            queue<TreeNode*>q;
            unordered_set<TreeNode*>visited;
            q.push(i);
            visited.insert(i);
            for(int dist=0;dist<=distance;dist++)
            {
            int size=q.size();
            while(size--)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(curr!=i&&st.count(curr))
                {
                    count++;
                }
                for(auto nei:adj[curr])
                {
                    if(!visited.count(nei))
                    {
                        q.push(nei);
                        visited.insert(nei);
                    }
                }
            }
            }
        }
        return count/2;
    }
};
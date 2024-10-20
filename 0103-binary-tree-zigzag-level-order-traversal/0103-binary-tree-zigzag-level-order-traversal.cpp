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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int flag=1;
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++)
            {
                TreeNode* front=q.front();
                q.pop();
                if(flag==1)
                {
                    temp[i]=front->val;
                }
                else
                {
                    temp[n-i-1]=front->val;
                }
                if(front->left)
                {
                    q.push(front->left);
                }
                if(front->right)
                {
                    q.push(front->right);
                }
            }
            flag=-(flag);
            ans.push_back(temp);
        }
        return ans;
    }
};
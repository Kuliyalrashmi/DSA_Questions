/* To find the top view of binary Tree */
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    vector<int>ans;
    queue<pair<TreeNode<int>*,int>>q;
    map<int,int>mp;
    q.push({root,0});
    while(!q.empty())
    {
        auto x=q.front();
        q.pop();
        TreeNode<int> *curr=x.first;
        int index=x.second;
        if(mp.find(index)==mp.end())
        {
            mp[index]=curr->data;
        }
        if(curr->left)
        {
            q.push({curr->left,index-1});
        }
        if(curr->right)
        {
            q.push({curr->right,index+1});
        }
    }
    for(auto i:mp)
    {
        ans.push_back(i.second);
    }
    return ans;
}


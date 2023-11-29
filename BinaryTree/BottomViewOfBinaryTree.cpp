/* To Find the bottom view of Binary tree */
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
vector<int> bottomView(TreeNode<int> * root){
   vector<int>ans;
   queue<pair<TreeNode<int>*,int>>q;
   map<int,int>mp;
   q.push({root,0});
   while(!q.empty())
   {
       auto x=q.front();
       q.pop();
       TreeNode<int>*curr=x.first;
       int index=x.second;
       mp[index]=curr->data;
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

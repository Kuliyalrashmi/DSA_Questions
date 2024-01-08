/*   Root to Node Path In A binary Tree

Problem Statement: Print Root to Node Path In A Binary Tree. Write a program to print path from root to a given node in a binary tree.

Problem Description: 

We are given a binary tree T and a node V. We need to print a path from the root of the tree to the node.

Note:

No two nodes in the tree have the same data value.
It is assured that the node V is present and a path always exists.

*/

/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/
void solve(BinaryTreeNode<int> * root,vector<int>&ans,vector<string>&final)
{
    if(!root)
    {
        return;
    }
    ans.push_back(root->data);
    if(root->left!=NULL)
    {
        solve(root->left,ans,final);
    }
    if(root->right)
    {
        solve(root->right,ans,final);
    }
    if(root->left==NULL&&root->right==NULL)
    {
        string temp="";
        for(auto i:ans)
        {
            temp+=to_string(i);
            temp+=" ";
        }
        final.push_back(temp);
    }
    ans.pop_back();
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    vector<int>ans;
    vector<string>final;
    if(!root)
    {
        return final;
    }
    solve(root,ans,final);
    return final;
}

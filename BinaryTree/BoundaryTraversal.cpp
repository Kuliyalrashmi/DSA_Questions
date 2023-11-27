/* Write a program for the Anti-Clockwise Boundary traversal of a binary tree.*/
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root)
{
    return (root->left==NULL)&&(root->right==NULL);
}
void addLeft(TreeNode<int>*root,vector<int>&ans)
{
    TreeNode<int>*curr=root->left;

    while(curr!=NULL)
    {
        if (!isLeaf(curr)) 
        {
           ans.push_back(curr -> data);
        }
        if(curr->left!=NULL)
        {
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
}
void addRight(TreeNode<int>*root,vector<int>&ans)
{
    TreeNode<int>*curr=root->right;
    vector<int>temp;
    while(curr!=NULL)
    {
        if (!isLeaf(curr))
        {
            temp.push_back(curr->data);
        }
       if(curr->right!=NULL)
       {
           curr=curr->right;
       }
       else
       {
           curr=curr->left;
       }
    }
    for(int i=temp.size()-1;i>=0;i--)
    {
        ans.push_back(temp[i]);
    }
}
void addLeaf(TreeNode<int>*root,vector<int>&ans)
{
    if(isLeaf(root)==true)
    {
        ans.push_back(root->data);
        return;
    }
    if(root->left!=NULL)
    {
       addLeaf(root->left,ans);
    }
    if(root->right!=NULL)
    {
        addLeaf(root->right,ans);
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int>ans;
    if(!root)
    {
        return ans;
    }
    if(!isLeaf(root))
    {
        ans.push_back(root->data);
    }
    addLeft(root,ans);
    addLeaf(root,ans);
    addRight(root,ans);
    return ans;
}

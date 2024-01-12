/*  Kth Smallest Node In BST

Given a binary search tree and an integer ‘K’. Your task is to find the ‘K-th’ smallest element 
in the given BST( binary search tree).

BST ( binary search tree) -

If all the smallest nodes on the left side and all the greater nodes on the right side of the node current node.

*/


/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(T x) : data(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : data(x), left(left), right(right) {}
    };

************************************************************/
void inorder(TreeNode<int>*root,int k,int& no,int& count)
{
    if(root==NULL||count>=k)
    {
        return;
    }
    inorder(root->left,k,no,count);
    count++;
    if(count==k)
    {
        no=root->data;
        return;
    }
    inorder(root->right,k,no,count);
}
int kthSmallest(TreeNode<int> *root, int k)
{
    int ans=0,count=0;
    inorder(root,k,ans,count);
    return ans;
}

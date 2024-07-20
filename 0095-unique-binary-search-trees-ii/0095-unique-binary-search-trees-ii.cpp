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
    vector<TreeNode*>built(int left,int right)
    {
        if(left>right)
        {
            return {NULL};
        }
        if(left==right)
        {
            TreeNode*root=new TreeNode(left);
            return {root};
        }
        vector<TreeNode*>result;
        for(int i=left;i<=right;i++)
        {
            vector<TreeNode*>leftSubtree=built(left,i-1);
            vector<TreeNode*>rightSubtree=built(i+1,right);
            for(TreeNode*leftRoot:leftSubtree)
            {
                for(TreeNode*rightRoot:rightSubtree)
                {
                TreeNode*currRoot=new TreeNode(i);
                currRoot->left=leftRoot;
                currRoot->right=rightRoot;
                result.push_back(currRoot);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return built(1,n);
    }
};
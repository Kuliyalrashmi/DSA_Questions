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
    bool solve(TreeNode* root, int value, string& str) {
        if (!root) return false;
        if (root->val == value) return true;
        
        str.push_back('L');
        if (solve(root->left, value, str))
        return true;
        str.pop_back();
        
        str.push_back('R');
        if (solve(root->right, value, str)) 
        return true;
        str.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string root_src="",root_dest="";
        solve(root,startValue,root_src);
        solve(root,destValue,root_dest);
        int index=0;
        while(index<root_src.size()&&index<root_dest.size()&&root_src[index]==root_dest[index])
        {
            index++;
        }
        string ans="";
        for(int i=0;i<(root_src.size()-index);i++)
        {
            ans.push_back('U');
        }
         for(int i=index;i<root_dest.size();i++)
        {
            ans.push_back(root_dest[i]);
        }
        return ans;
    }
};
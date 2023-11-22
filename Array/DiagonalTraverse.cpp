/* Leetcode Question no 498 Diagonal Traverse
Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>ans;
        int m=mat.size(),n=mat[0].size();
        map<int,vector<int>>mp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mp[i+j].push_back(mat[i][j]);
            }
        }
        int turn=1;
        for(auto &i:mp)
        {
            if(turn)
            {
                reverse(i.second.begin(),i.second.end());
            }
            for(auto &num:i.second)
            {
                ans.push_back(num);
            }
            turn=1-turn;
        }
        return ans;
    }
};




/*Leetcode Question No 1424 Diagonal Traverse II
Given a 2D integer array nums, return all elements of nums in diagonal order as shown in the below images.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int n=nums.size();
        map<int,vector<int>>mp;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        vector<int>ans;
        for(auto&it:mp)
        {
            for(auto&num:it.second)
            {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

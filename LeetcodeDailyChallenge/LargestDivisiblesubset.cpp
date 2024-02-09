/*  9-Feb-2024
Leetcode Question no 368 Largest Divisible Subset 
Given a set of distinct positive integers nums, return the largest subset answer such that every pair
(answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

*/

/* Recursion */
class Solution {
public:
    void solve(int index,vector<int>&nums,vector<int>&ans,vector<int>&temp,int previous)
    {
        if(index>=nums.size())
        {
            if(temp.size()>ans.size())
            {
                ans=temp;
            }
            return;
        }
        if(previous==-1||nums[index]%previous==0)
        {
            temp.push_back(nums[index]);
            solve(index+1,nums,ans,temp,nums[index]);
            temp.pop_back();
        }
        solve(index+1,nums,ans,temp,previous);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>dp(1001,-1);
        vector<int>ans,temp;
        int previous=-1;
        solve(0,nums,ans,temp,previous);
        return ans;
    }
};
/* Bottom Up */

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>prev(n,-1);
        int prev_index=0,max_size=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[i]<dp[j]+1)
                    {
                        dp[i]=dp[j]+1;
                        prev[i]=j;
                    }
                    if(dp[i]>max_size)
                    {
                        max_size=dp[i];
                        prev_index=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(prev_index>=0)
        {
            ans.push_back(nums[prev_index]);
            prev_index=prev[prev_index];
        }
        return ans;
    }
};

/* 21-Jan-2024
Leetcode Question no 198 House Robber
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that
adjacent houses have security systems connected and it will automatically contact the police
if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

*/
class Solution {
public:
    int solve(vector<int>& nums,int n)
    {
        vector<int>dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
           int inc=nums[i];
           if(i>1)
           {
                inc=dp[i-2]+nums[i];
           }
           int exc=dp[i-1]+0;
           dp[i]=max(inc,exc);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(nums,n);
    }
};

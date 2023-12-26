/*       26 - Dec - 2023
Leetcode Question no 115 Number Of Dice Rolls With Target
You have n dice, and each die has k faces numbered from 1 to k.
Given three integers n, k, and target, return the number of possible ways 
(out of the kn total ways) to roll the dice, so the sum of the face-up numbers equals target. 
Since the answer may be too large, return it modulo 109 + 7.

  */

class Solution {
public:
    int solve(int n,int k,int target,vector<vector<int>>&dp)
    {
        if(target<0||n==0)
        {
            return target==0?1:0;
        }
        if(dp[n][target]!=-1)
        {
            return dp[n][target];
        }
        int sum=0;
        for(int i=1;i<=k;i++)
        {
            sum+=solve(n-1,k,target-i,dp);
            sum%=(int)1e9+7;
        }
        return dp[n][target]=sum;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(n,k,target,dp);
    }
};

/*  27-Jan-2024
Leetcode Question no 629 K Inverse Pairs Array
For an integer array nums, an inverse pair is a pair of integers [i, j] 
where 0 <= i < j < nums.length and nums[i] > nums[j].

Given two integers n and k, return the number of different arrays consist of numbers from 1 to n 
such that there are exactly k inverse pairs. Since the answer can be huge, return it modulo 109 + 7.

*/

class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int k,int dp[1001][1001])
    {
        if(n==0)
        {
            return 0;
        }
        if(k==0)
        {
            return 1;
        }
        if(dp[n][k]!=-1)
        {
            return dp[n][k];
        }
        int total=0;
        for(int i=0;i<=min(n-1,k);i++)
        {
            total=(total+solve(n-1,k-i,dp)%mod)%mod;
        }
        return dp[n][k]=total;
    }
    int kInversePairs(int n, int k) {
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return solve(n,k,dp);
    }
};

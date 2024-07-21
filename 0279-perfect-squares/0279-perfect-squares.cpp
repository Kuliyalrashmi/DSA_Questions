class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n==0)
        {
           return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int i=1,mini=INT_MAX;
        while((i*i)<=n)
        {
            int result=1+solve((n-(i*i)),dp);
            mini=min(result,mini);
            i++;
        }
        return dp[n]=mini;
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};
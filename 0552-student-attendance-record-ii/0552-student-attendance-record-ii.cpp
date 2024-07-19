class Solution {
public:
    int mod=1e9+7;
    int solve(int n,int absent,int late,int dp[100001][2][3])
    {
        if(late>=3||absent>=2)
        {
            return 0;
        }
        if(n==0)
        {
            return 1;
        }
        if(dp[n][absent][late]!=-1)
        {
            return dp[n][absent][late];
        }
        int A=solve(n-1,absent+1,0,dp)%mod;
        int l=solve(n-1,absent,late+1,dp)%mod;
        int p=solve(n-1,absent,0,dp)%mod;
        return dp[n][absent][late]=((A+l)%mod+p)%mod;
    }
    int checkRecord(int n) {
        int dp[100001][2][3];
        memset(dp,-1,sizeof(dp));
        return solve(n,0,0,dp);
    }
};
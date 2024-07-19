class Solution {
public:
    int solve(int i,string &s,int n,vector<int>&dp)
    {
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        if(i==n)
        {
            return dp[i]=1;
        }
        if(s[i]=='0')
        {
            return dp[i]=0;
        }
        int ans=solve(i+1,s,n,dp);
        if(i+1<n)
        {
            if(s[i]=='1'||s[i]=='2'&&s[i+1]<='6')
            {
                ans+=solve(i+2,s,n,dp);
            }
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        vector<int>dp(101,-1);
        int n=s.size();
        return solve(0,s,n,dp);
    }
};
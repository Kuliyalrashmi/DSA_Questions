class Solution {
public:
    int solve(string s,string str)
    {
        int m=s.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==str[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][m];
    }
    int longestPalindromeSubseq(string s) {
        string str=s;
        reverse(s.begin(),s.end());
        int ans=0;
        ans=solve(s,str);
        return ans;
    }
};
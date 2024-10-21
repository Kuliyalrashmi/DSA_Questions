class Solution {
public:
    int LongestPalindromic(string original,string reverse,int m,int n)
    {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(original[i-1]==reverse[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    int minInsertions(string s) {
        int n=s.size();
        string original=s;
        reverse(s.begin(),s.end());
        int k=LongestPalindromic(original,s,n,n);
        return n-k;
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>>dp(501,vector<int>(501,0));
        for(int i=0;i<=m;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    int insert=dp[i][j-1];
                    int to_delete=dp[i-1][j];
                    int replace=dp[i-1][j-1];
                    dp[i][j]=1+min({insert,to_delete,replace});
                }
            }
        }
        return dp[m][n];
    }
};
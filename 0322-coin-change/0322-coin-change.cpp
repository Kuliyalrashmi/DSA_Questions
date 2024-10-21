class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,INT_MAX-1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=amount;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=j==0?0:INT_MAX-1;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=min(0+dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else
                {
                    dp[i][j]=0+dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==INT_MAX-1?-1:dp[n][amount];
    }
};
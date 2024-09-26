class Solution {
public:
    int solve(int index,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(amount<=0||index>=coins.size())
        {
            if(amount==0)
            {
                return 0;
            }
            return INT_MAX-1;
        }
        if(dp[index][amount]!=-1)
        {
            return dp[index][amount];
        }
        if(coins[index]>amount)
        {
            dp[index][amount]=0+solve(index+1,coins,amount,dp);
        }
        else
        {
            int include=1+solve(index,coins,amount-coins[index],dp);
            int exclude=0+solve(index+1,coins,amount,dp);
            dp[index][amount]=min(include,exclude);
        }
        return dp[index][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=solve(0,coins,amount,dp);
        if(ans==INT_MAX-1)
        {
            return -1;
        }
        return ans;
    }
};
class Solution {
public:
    int solve(vector<int>&coins,int index,int target,vector<vector<int>>&dp)
    {
        if(index>=coins.size()||target<=0)
        {
            if(target==0)
            {
                return 0;
            }
            return INT_MAX-1;
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        int temp=-1;
        if(coins[index]>target)
        {
            int exclude=0+solve(coins,index+1,target,dp);
            dp[index][target]=temp=exclude;
        }
        else
        {
            int include=1+solve(coins,index,target-coins[index],dp);
            int exclude=0+solve(coins,index+1,target,dp);
            dp[index][target]=temp=min(include,exclude);
        }
        return dp[index][target]=temp;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        ans=solve(coins,0,amount,dp);
        if(ans==INT_MAX-1)
        {
            return -1;
        }
        return ans;
    }
};
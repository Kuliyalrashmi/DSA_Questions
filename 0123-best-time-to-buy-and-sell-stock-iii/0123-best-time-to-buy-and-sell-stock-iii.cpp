class Solution {
public:
    int solve(int index,int buy,int sell,vector<int>&prices,int n,vector<vector<vector<int>>>&dp)
    {
        if(index==n||sell==0)
        {
            return 0;
        }
        if(dp[index][buy][sell]!=-1)
        {
            return dp[index][buy][sell];
        }
        if(buy==1)
        {
            int include=-prices[index]+solve(index+1,0,sell,prices,n,dp);
            int exclude=0+solve(index+1,1,sell,prices,n,dp);
            return dp[index][buy][sell]=max(include,exclude);
        }
        int Sell=prices[index]+solve(index+1,1,sell-1,prices,n,dp);
        int notSell=0+solve(index+1,0,sell,prices,n,dp);
        return dp[index][buy][sell]=max(Sell,notSell);
    }
    int maxProfit(vector<int>& prices) {
       int n=prices.size(); 
       vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,n,dp);
    }
};
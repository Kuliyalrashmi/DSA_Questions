class Solution {
public:
    int invest(vector<int>&prices,int buy,int index,vector<vector<int>>&dp)
    {
        if(index==prices.size())
        {
            return 0;
        }
        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }
        int profit=0;
        if(buy)
        {
            profit=max((-prices[index]+invest(prices,0,index+1,dp)),0+invest(prices,1,index+1,dp));
        }
        else
        {
            profit=max((+prices[index]+invest(prices,1,index+1,dp)),0+invest(prices,0,index+1,dp));
        }
        dp[index][buy]=profit;
        return dp[index][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return invest(prices,1,0,dp);
    }
};
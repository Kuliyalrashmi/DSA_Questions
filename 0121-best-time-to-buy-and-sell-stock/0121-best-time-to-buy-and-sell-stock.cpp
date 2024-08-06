class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit=INT_MIN,min_price=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            min_price=min(prices[i],min_price);
            int profit=prices[i]-min_price;
            max_profit=max(max_profit,profit);
        }
        return max_profit;
    } 
};
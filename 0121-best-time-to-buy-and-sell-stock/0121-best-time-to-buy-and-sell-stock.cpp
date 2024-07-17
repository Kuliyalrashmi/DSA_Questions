class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int max_profit=INT_MIN,min_price=prices[0];
       for(int i=0;i<n;i++)
       {
           min_price=min(prices[i],min_price);
           int profit=prices[i]-min_price;
           max_profit=max(max_profit,profit);
       }
        return max_profit;
    }
};
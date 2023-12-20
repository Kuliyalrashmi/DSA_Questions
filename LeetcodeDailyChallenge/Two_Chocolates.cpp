/*    20 - Dec - 2023
  
Leetcode Question no 2706 Buy Two Chocolates
You are given an integer array prices representing the prices of various chocolates in a store. 
You are also given a single integer money, which represents your initial amount of money.
You must buy exactly two chocolates in such a way that you still have some non-negative leftover money.
You would like to minimize the sum of the prices of the two chocolates you buy.
Return the amount of money you will have leftover after buying the two chocolates.
If there is no way for you to buy two chocolates without ending up in debt, return money. 
  
Note that the leftover must be non-negative.
*/

/* Approach 1 using Sorting */

class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int cost_two=prices[0]+prices[1];
        if(cost_two<=money)
        {
            return money-cost_two;
        }
        return money;
    }
};


/* Approach 2 Without using Sorting */
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int smallest=INT_MAX,Second_small=INT_MAX;
        for(auto i:prices)
        {
            if(i<=smallest)
            {
                Second_small=smallest;
                smallest=i;
            }
            else if(i>smallest&&i<Second_small)
            {
                Second_small=i;
            }
        }
        int cost=Second_small+smallest;
        return cost<=money?money-cost:money;
    }
};

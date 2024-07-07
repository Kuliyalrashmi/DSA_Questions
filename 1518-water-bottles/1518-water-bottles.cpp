class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum=numBottles+(numBottles)/(numExchange-1);
        if(numBottles%(numExchange-1)==0)
        {
            sum--;
        }
        return sum;
    }
};
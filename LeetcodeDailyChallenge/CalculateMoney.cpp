/*  6 Dec 2023
Leetcode Question no 1716 Calculate Money IN Leetcode Bank
Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.
He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, 
he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.
Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.
*/

class Solution {
public:
    int totalMoney(int n) {
        int initial=1,no=1;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=no;
            no++;
            if(i%7==0)
            {
                initial++;
                no=initial;
            }
        }
        return ans;
    }
};

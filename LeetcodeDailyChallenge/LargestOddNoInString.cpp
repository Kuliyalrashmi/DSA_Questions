/*  7- Dec-2023
Leetcode Question no 1903 Largest Odd Number In a String
You are given a string num, representing a large integer. 
Return the largest-valued odd integer (as a string) that is a non-empty substring of num, 
or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
*/

class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        for(int i=n-1;i>=0;i--)
        {
            if(num[i]%2==0)
            {
                num.pop_back();
            }
            else
            {
                return num;
            }
        }
        return num;
    }
};

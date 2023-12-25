/*   25-Dec-2023
Leetcode Question no 91  Decode Ways
A message containing letters from A-Z can be encoded into numbers using the following mapping:
'A' -> "1"
'B' -> "2"
...
'Z' -> "26"
To decode an encoded message, all the digits must be grouped then mapped back into letters 
using the reverse of the mapping above (there may be multiple ways). For example, "11106" can be mapped into:
"AAJF" with the grouping (1 1 10 6)
"KJF" with the grouping (11 10 6)
Note that the grouping (1 11 06) is invalid because "06" cannot be mapped into 'F' since "6" is different from "06".
Given a string s containing only digits, return the number of ways to decode it.
The test cases are generated so that the answer fits in a 32-bit integer.
*/

/* Recursion + Memoization */

class Solution {
public:
    int solve(int i,string s,int n,vector<int>&dp)
    {
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        if(i==n)
        {
            return dp[i]=1;
        }
        if(s[i]=='0')
        {
            return dp[i]=0;
        }
        int result=solve(i+1,s,n,dp);
        if(i+1<n)
        {
            if(s[i]=='1'||s[i]=='2'&&s[i+1]<='6')
            {
                result+=solve(i+2,s,n,dp);
            }
        }
        return dp[i]=result;
    }
    int numDecodings(string s) {
       vector<int>dp(101,-1);
       int n=s.size();
       return solve(0,s,n,dp); 
    }
};

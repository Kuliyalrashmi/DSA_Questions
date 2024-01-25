/*    25-Jan-2024
Leetcode Questiono no 1143 Longest Common Subsequences
Given two strings text1 and text2, return the length of their longest common subsequence.
If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) 
deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

*/

/* Recursion */

class Solution {
public:
    int solve(string text1, string text2,int m,int n)
    {
        if(m==0||n==0)
        {
            return 0;
        }
        if(text1[m-1]==text2[n-1])
        {
            return 1+solve(text1,text2,m-1,n-1);
        }
        else
        {
            return max(solve(text1,text2,m-1,n),solve(text1,text2,m,n-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        return solve(text1,text2,m,n);
    }
};


/* Top Down Approach */

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

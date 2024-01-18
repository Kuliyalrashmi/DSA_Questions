/*    18-Jan-2024

Leetcode Question no 70 Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

*/

/* APPROACH 1 RECURSION */

class Solution {
public:
    int climbStairs(int n) {
        if(n==0||n==1)
            return 1;
        else 
            return climbStairs(n-1)+climbStairs(n-2);
    }
};


/* APPROACH 2 MEMOIZATION */

class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
          if(n==0||n==1)
          {
            return 1;
          }
          if(dp[n]!=-1)
          {
              return dp[n];
          }
          dp[n]=solve(n-1,dp)+solve(n-2,dp);
          return dp[n];

    }
    int climbStairs(int n) {
      vector<int>dp(n+1,-1);
      return solve(n,dp);
    }
};



/*  APPROACH 3 TOP DOWN APPROACH  AND SPACE OPTIMIZATION */

class Solution {
public:
    int solve(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
       return dp[n];
    }
    int climbStairs(int n) {
      return solve(n);
    }
};



class Solution {
public:
    int climbStairs(int n) {
        if(n<=2)
            return n;
        int x=1,y=2;
        for(int i=3;i<n;i++)
        {
            int temp=y;
            y=y+x;
            x=temp;
        }
       
        return (x+y);
           
    }
};


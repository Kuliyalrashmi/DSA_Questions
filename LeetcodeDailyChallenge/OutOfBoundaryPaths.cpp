/*  26-Jan-2024

Leetcode Question no 576 Out Of Boundary Path
There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. 
You are allowed to move the ball to one of the four adjacent cells in the grid 
(possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.

Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball 
out of the grid boundary. Since the answer can be very large, return it modulo 109 + 7.

  */

class Solution {
public:
    int  mod =1e9+7;
    int solve(int m,int n,int maxMove,int startRow,int startColumn,int dp[51][51][51],vector<vector<int>>&directions)
    {
        if(startRow<0||startRow>=m||startColumn<0||startColumn>=n)
        {
            return 1;
        }
        if(maxMove<=0)
        {
            return 0;
        }
        if(dp[maxMove][startRow][startColumn]!=-1)
        {
            return dp[maxMove][startRow][startColumn];
        }
        int result=0;
        for(int i=0;i<4;i++)
        {
            int nr=startRow+directions[i][0];
            int nc=startColumn+directions[i][1];
            result=(result+solve(m,n,maxMove-1,nr,nc,dp,directions))%mod;
        }
        return dp[maxMove][startRow][startColumn]=result%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int dp[51][51][51];
        memset(dp,-1,sizeof(dp));
        vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
        return solve(m,n,maxMove,startRow,startColumn,dp,directions);
    }
};

class Solution {
public:
    int solve(vector<vector<int>>& grid,int m,int n,vector<vector<int>>&dp)
    {
        if(m==0&&n==0)
        {
            dp[m][n]=grid[m][n];
        }
        if(m<0||n<0)
        {
            return INT_MAX;
        }
        if(dp[m][n]!=-1)
        {
            return dp[m][n];
        }
        int left=solve(grid,m,n-1,dp);
        int up=solve(grid,m-1,n,dp);
        dp[m][n]=min(left,up)+grid[m][n];
        return dp[m][n];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(grid,m-1,n-1,dp);
    }
};
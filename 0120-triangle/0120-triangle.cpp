class Solution {
public:
    int solve(vector<vector<int>>& triangle,int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i==n-1)
        {
            return triangle[i][j];
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int same=triangle[i][j]+solve(triangle,n,i+1,j,dp);
        int diagonal=triangle[i][j]+solve(triangle,n,i+1,j+1,dp);
        return dp[i][j]=min(same,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(triangle,n,0,0,dp);
    }
};
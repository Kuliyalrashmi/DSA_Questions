class Solution {
public:
    int solve(vector<vector<char>>&matrix,int i,int j,int &squares,vector<vector<int>>&dp)
    {
        if(i>=matrix.size()||j>=matrix[0].size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int right=solve(matrix,i,j+1,squares,dp);
        int diagonal=solve(matrix,i+1,j+1,squares,dp);
        int down=solve(matrix,i+1,j,squares,dp);
        if(matrix[i][j]=='1')
        {
            dp[i][j]=1+min(right,min(diagonal,down));
            squares=max(squares,dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int squares=0;
        vector<vector<int>>dp(matrix.size()+1,vector<int>(matrix[0].size()+1,-1));
        solve(matrix,0,0,squares,dp);
        return squares*squares;
    }
};
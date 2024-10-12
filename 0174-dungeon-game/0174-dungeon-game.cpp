class Solution {
public:
    int solve(vector<vector<int>>& dungeon,int row,int col,vector<vector<int>>&dp)
    {
        if(row==dungeon.size()-1&&col==dungeon[0].size()-1)
        {
            return dungeon[row][col]>=0?1:1-dungeon[row][col];
        }
        if(row>=dungeon.size()||col>=dungeon[0].size())
        {
            return INT_MAX;
        }
        if(dp[row][col]!=INT_MAX)
        {
            return dp[row][col];
        }
        int right=solve(dungeon,row,col+1,dp);
        int down=solve(dungeon,row+1,col,dp);
        int health=min(right,down)-dungeon[row][col];
        dp[row][col]=health<=0?1:health;
        return dp[row][col];
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        return solve(dungeon,0,0,dp);
    }
};
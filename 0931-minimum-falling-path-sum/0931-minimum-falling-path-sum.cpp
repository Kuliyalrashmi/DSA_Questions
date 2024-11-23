class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<m;j++)
            {

               dp[i][j] = matrix[i][j] + min({dp[i-1][j], dp[i-1][max(j-1,0)], dp[i-1][min(j+1,m-1)]});

            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};
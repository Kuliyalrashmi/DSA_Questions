/*  14-Dec-2023
Leetcode Question Number 2482 Difference Between Ones And Zeros In Row And Column

You are given a 0-indexed m x n binary matrix grid.
A 0-indexed m x n difference matrix diff is created with the following procedure:
Let the number of ones in the ith row be onesRowi.
Let the number of ones in the jth column be onesColj.
Let the number of zeros in the ith row be zerosRowi.
Let the number of zeros in the jth column be zerosColj.
diff[i][j] = onesRowi + onesColj - zerosRowi - zerosColj
Return the difference matrix diff.

*/

/* Brute Force Approach (but It gives Time Limit Exceeded */

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        int row=0,col=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                row=i,col=j;
                int OnesR=0,OnesC=0,ZeroR=0,ZeroC=0;
                for(int k=0;k<m;k++)
                {
                    if(grid[row][k]==1)
                    {
                        OnesR++;
                    }
                    else
                    {
                        ZeroR++;
                    }
                }
                for(int k=0;k<n;k++)
                {
                    if(grid[k][col]==1)
                    {
                        OnesC++;
                    }
                    else
                    {
                        ZeroC++;
                    }
                }
                int diff=OnesR+OnesC-ZeroR-ZeroC;
                ans[row][col]=diff;
            }
        }
        return ans;
    }
};





/* Better Approach But With n+m Space Complexity */

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        vector<int>OnesR(n,0);
        vector<int>OnesC(m,0);
        vector<int>ZerosR(n,0);
        vector<int>ZerosC(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    ZerosR[i]++;
                    ZerosC[j]++;
                }
                else
                {
                    OnesR[i]++;
                    OnesC[j]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int diff=OnesR[i]+OnesC[j]-ZerosR[i]-ZerosC[j];
                ans[i][j]=diff;
            }
        }
        return ans;
    }
};

 

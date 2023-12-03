/* 
Leetcode Question no 542 01 Matrix
Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two adjacent cells is 1.
*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                    visited[i][j]=1;
                }
            }
        }
        vector<int>del_r={-1,0,1,0};
        vector<int>del_c={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nc>=0&&nc<n&&nr>=0&&nr<m&&visited[nr][nc]!=1)
                {
                    q.push({nr,nc});
                    mat[nr][nc]=mat[r][c]+1;
                    visited[nr][nc]=1;
                }
            }
        }
        return mat;
    }
};

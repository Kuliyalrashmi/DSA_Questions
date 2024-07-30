class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        queue<pair<int,int>>pq;
        int visited[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    pq.push({i,j});
                    visited[i][j]=1;
                }
                else
                {
                    visited[i][j]=0;
                }
            }
        }
        int del_row[4]={0,0,-1,1};
        int del_col[4]={-1,1,0,0};
        while(!pq.empty())
        {
            int row=pq.front().first;
            int col=pq.front().second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+del_row[i];
                int nc=col+del_col[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&!visited[nr][nc])
                {
                    mat[nr][nc]=mat[row][col]+1;
                    visited[nr][nc]=1;
                    pq.push({nr,nc});
                }
            }
        }
        return mat;
    }
};
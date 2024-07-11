class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
       int m=grid.size(),n=grid[0].size();
       queue<pair<int,int>>pq;
       vector<vector<int>>visited(m,vector<int>(n,0));
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i==0 || j==0 || i==m-1 || j==n-1)
               {
                  if(grid[i][j]==1)
                  {
                     pq.push({i,j});
                     visited[i][j]=1;
                  }
               }
           }
       }
       int del_row[4]={-1,0,1,0};
       int del_col[4]={0,-1,0,1};
       while(!pq.empty())
       {
           int row=pq.front().first;
           int col=pq.front().second;
           pq.pop();
           for(int i=0;i<4;i++)
           {
               int nr=row+del_row[i];
               int nc=col+del_col[i];
               if(nr>=0&&nr<m&&nc>=0&&nc<n&&!visited[nr][nc]&&grid[nr][nc]==1)
               {
                   pq.push({nr,nc});
                   visited[nr][nc]=1;
               }
           }
       }
       int enclaves=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(!visited[i][j]&&grid[i][j]==1)
               {
                   enclaves++;
               }
           }
       }
      return enclaves;
    }
};
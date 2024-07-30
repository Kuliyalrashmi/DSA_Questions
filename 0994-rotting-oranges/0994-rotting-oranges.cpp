class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        queue<pair<pair<int,int>,int>>pq;
        int visited[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    pq.push({{i,j},0});
                    visited[i][j]=2;
                }
                else
                {
                    visited[i][j]=0;
                }
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }
      int del_row[4]={-1,1,0,0};
      int del_col[4]={0,0,-1,1};
      int time=0,cnt=0;
      while(!pq.empty())
      {
          int row=pq.front().first.first;
          int col=pq.front().first.second;
          int t=pq.front().second;
          time=max(t,time);
          pq.pop();
          for(int i=0;i<4;i++)
          {
              int nr=row+del_row[i];
              int nc=col+del_col[i];
              if(nr>=0&&nr<m&&nc>=0&&nc<n&&visited[nr][nc]!=2&&grid[nr][nc]==1)
              {
                  pq.push({{nr,nc},t+1});
                  visited[nr][nc]=2;
                  cnt++;
              }
          }
      }
    if(count!=cnt)
    {
        return -1;
    }
    return time;   
    }
};
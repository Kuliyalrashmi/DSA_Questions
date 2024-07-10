class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size(),count=0,cnt=0;
        queue<pair<pair<int,int>,int>>pq;
        int visited[rows][cols];
        for(int i=0;i<rows;i++)
        {
             for(int j=0;j<cols;j++)
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
        int time=0;
        int del_row[4]={-1,0,1,0};
        int del_col[4]={0,1,0,-1};
        while(!pq.empty())
        {
            int r=pq.front().first.first;
            int c=pq.front().first.second;
            int t=pq.front().second;
            time=max(time,t);
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+del_row[i];
                int nc=c+del_col[i];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols&&visited[nr][nc]!=2&&grid[nr][nc]==1)
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
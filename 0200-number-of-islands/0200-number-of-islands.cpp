class Solution {
public:
    void bfs(int i,int j,vector<vector<char>>&grid)
    {
        grid[i][j]='@';
        queue<pair<int,int>>pq;
        pq.push({i,j});
        while(!pq.empty())
        {
            int x=pq.front().first;
            int y=pq.front().second;
            pq.pop();
            int del_row[4]={-1,1,0,0};
            int del_col[4]={0,0,-1,1};
            for(int i=0;i<4;i++)
            {
                int nx=x+del_row[i];
                int ny=y+del_col[i];
                if(nx>=0&&nx<grid.size()&&ny>=0&&ny<grid[0].size()&&grid[nx][ny]=='1')
                {
                    pq.push({nx,ny});
                    grid[nx][ny]='@';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};
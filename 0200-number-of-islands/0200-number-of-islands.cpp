class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>&visited,vector<vector<char>>&grid)
    {
        visited[row][col]=1;
        queue<pair<int,int>>pq;
        pq.push({row,col});
        while(!pq.empty())
        {
            int r=pq.front().first;
            int c=pq.front().second;
            pq.pop();
            int del_row[]={-1,0,1,0};
            int del_col[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int n_r=r+del_row[i];
                int n_c=c+del_col[i];
                if(n_r>=0&&n_r<grid.size()&&n_c>=0&&n_c<grid[0].size()&&!visited[n_r][n_c]&&grid[n_r][n_c]=='1')
                {
                    pq.push({n_r,n_c});
                    visited[n_r][n_c]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int count=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j]&&grid[i][j]=='1')
                {
                    bfs(i,j,visited,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
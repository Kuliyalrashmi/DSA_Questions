class Solution {
public:
    void bfs(vector<vector<char>>&grid,int row,int col,int m,int n,vector<vector<int>>&visited)
    {
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int del_row[4]={-1,0,1,0};
        int del_col[4]={0,-1,0,1};
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int n_r=r+del_row[i];
                int n_c=c+del_col[i];
                if(n_r>=0&&n_r<m&&n_c>=0&&n_c<n&&!visited[n_r][n_c]&&grid[n_r][n_c]=='1')
                {
                    q.push({n_r,n_c});
                    visited[n_r][n_c]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        int islands=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1'&&!visited[i][j])
                {
                    bfs(grid,i,j,m,n,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};
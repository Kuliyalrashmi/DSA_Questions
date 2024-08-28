class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m,int n, bool &island)
    {
        if(grid1[i][j]!=grid2[i][j])
        {
            island=false;
        }
        grid2[i][j]=0;
        grid1[i][j]=0;
        int del_row[4]={-1,0,1,0};
        int del_col[4]={0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int x=i+del_row[k];
            int y=j+del_col[k];
            if(x>=0&&y>=0&&x<m&&y<n&&grid2[x][y]==1)
            {
                dfs(x,y,grid1,grid2,m,n,island);
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans=0,m=grid2.size(),n=grid2[0].size();
        bool island=false;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j]==1)
                {
                    island=true;
                    dfs(i,j,grid1,grid2,m,n,island);
                    if(island)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
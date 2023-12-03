/* 
Leetcode Question no 994 Rotting Oranges
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int count=0;
        int visited[rows][cols];
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
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
        int time=0,cnt=0;
        vector<int>del_r={-1,0,1,0};
        vector<int>del_c={0,1,0,-1};
        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time=max(time,t);
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols&&grid[nr][nc]==1&&visited[nr][nc]!=2)
                {
                    q.push({{nr,nc},t+1});
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

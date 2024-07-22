class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1||grid[n-1][n-1])
        {
            return -1;
        }
        queue<pair<pair<int,int>,int>>pq;
        pq.push({{0,0},1});
        if(grid[0][0]==0&&n==1&&n==1)return 1;
        while(!pq.empty())
        {
            int x=pq.front().first.first;
            int y=pq.front().first.second;
            int dist=pq.front().second;
            pq.pop();
            // if(x==n-1&&y==n-1)
            // {
            //     return dist+1;
            // }
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int new_x=x+i;
                    int new_y=y+j;
                    if(new_x>=0&&new_x<n&&new_y>=0&&new_y<n&&grid[new_x][new_y]==0)
                    {
                        if(new_x==n-1&&new_y==n-1)
                        {
                            return dist+1;
                        }
                        pq.push({{new_x,new_y},dist+1});
                        grid[new_x][new_y]=1;
                    }
                }
            }
        }
        return -1;
    }
};
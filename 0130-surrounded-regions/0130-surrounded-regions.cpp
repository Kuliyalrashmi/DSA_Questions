class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        queue<pair<int,int>>pq;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0||i==m-1||j==n-1)
                {
                    if(board[i][j]=='O')
                    {
                        pq.push({i,j});
                    }
                }
            }
        }
        int del_row[]={-1,0,1,0};
        int del_col[]={0,-1,0,1};
        while(!pq.empty())
        {
            int row=pq.front().first;
            int col=pq.front().second;
            board[row][col]='Y';
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+del_row[i];
                int nc=col+del_col[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]=='O')
                {
                    pq.push({nr,nc});
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='Y')
                {
                    board[i][j]='O';
                }
                else
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
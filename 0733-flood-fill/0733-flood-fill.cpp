class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         if(image[sr][sc]==color)
        {
            return image;
        }
        queue<pair<int,int>>pq;
        pq.push({sr,sc});
        int del_row[4]={-1,1,0,0};
        int del_col[4]={0,0,-1,1};
        int m=image.size(),n=image[0].size();
        int curr=image[sr][sc];
        image[sr][sc]=color;
        while(!pq.empty())
        {
            int row=pq.front().first;
            int col=pq.front().second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nr=row+del_row[i];
                int nc=col+del_col[i];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&image[nr][nc]==curr)
                {
                    image[nr][nc]=color;
                    pq.push({nr,nc});
                }
            }
        }
        return image;
    }
};
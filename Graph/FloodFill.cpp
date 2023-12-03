/*
Leetcode Question no 733 Flood Fill 
An image is represented by an m x n integer grid image where image[i][j] represents the pixel value of the image.
You are also given three integers sr, sc, and color. 
You should perform a flood fill on the image starting from the pixel image[sr][sc].
To perform a flood fill, consider the starting pixel, plus any pixels connected 4-directionally to 
the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally 
to those pixels (also with the same color), and so on. Replace the color of all of the aforementioned pixels with color.
Return the modified image after performing the flood fill.
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows=image.size(),cols=image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>visited(rows,vector<int>(cols,0));
        visited[sr][sc]=1;
        int ch=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            vector<int>del_r={-1,0,1,0};
            vector<int>del_c={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int nr=r+del_r[i];
                int nc=c+del_c[i];
                if(nr>=0&&nr<rows&&nc>=0&&nc<cols&&image[nr][nc]==ch&&visited[nr][nc]!=1)
                {
                    image[nr][nc]=color;
                    q.push({nr,nc});
                    visited[nr][nc]=1;
                }
            } 
        }
        return image;
    }
};

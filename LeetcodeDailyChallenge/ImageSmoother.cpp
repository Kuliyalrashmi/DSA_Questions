/*      19-Dec-2023
Leetcode Question no 661 Image Smoother
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding 
down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother).
If one or more of the surrounding cells of a cell is not present, we do not consider it in the average
(i.e., the average of the four cells in the red smoother).
*/


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(),n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum=0,cnt_neighb=0;
                for(int k=-1;k<=1;k++)
                {
                    for(int x=-1;x<=1;x++)
                    {
                        int nr=i+k;
                        int nc=j+x;
                        if(nr>=0&&nr<m&&nc>=0&&nc<n)
                        {
                            sum+=img[nr][nc];
                            cnt_neighb++;
                        }
                    }
                }
                ans[i][j]=sum/cnt_neighb;
            }
        }
        return ans;
    }
};






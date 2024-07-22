class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows=heights.size(),cols=heights[0].size();
        vector<vector<int>>ans(rows,vector<int>(cols,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        ans[0][0]=0;
        pq.push({0,{0,0}});
        int del_row[]={-1,0,1,0};
        int del_col[]={0,1,0,-1};
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++)
            {
                int nrow=row+del_row[i];
                int ncol=col+del_col[i];
                if(nrow>=0&&nrow<rows&&ncol>=0&&ncol<cols)
                {
                    int difference=abs(heights[row][col]-heights[nrow][ncol]);
                    int max_diff=max(ans[row][col],difference);
                    if(ans[nrow][ncol]>max_diff)
                    {
                        ans[nrow][ncol]=max_diff;
                        pq.push({max_diff,{nrow,ncol}});
                    }
                }
            }
        }
        return ans[rows-1][cols-1];
    }
};
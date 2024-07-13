class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>transpose;
        for(int i=0;i<n;i++)
        {
            vector<int>temp;
            for(int j=0;j<m;j++)
            {
                temp.push_back(grid[j][i]);
            }
            transpose.push_back(temp);
        }
        int ans=0;
        for(auto row1:grid)
        {
            for(auto row2:transpose)
            {
                if(row1==row2)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int lc=0,lr=0;
        vector<int>ans;
        while(lr<m&&lc<n)
        {
            for(int i=lc;i<n;i++)
            {
                ans.push_back(matrix[lr][i]);
            }
            lr++;
            for(int i=lr;i<m;i++)
            {
                ans.push_back(matrix[i][n-1]);
            }
            n--;
            if(lr<m)
            {
                for(int i=n-1;i>=lc;i--)
               {
                  ans.push_back(matrix[m-1][i]);
                }
               m--;
            }
            if(lc<n)
            {
                for(int i=m-1;i>=lr;i--)
                {
                    ans.push_back(matrix[i][lc]);
                }
                lc++;
            }
            
        }
        return ans;
    }
};
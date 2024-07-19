class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int j=0;
        vector<int>ans;
        while(j<n)
        {
            int maxi=INT_MIN,row_index=-1;
            for(int i=0;i<m;i++)
            {
                if(matrix[i][j]>maxi)
                {
                    maxi=matrix[i][j];
                    row_index=i;
                }
            }
            int mini=INT_MAX;
            for(int i=0;i<n;i++)
            {
                if(matrix[row_index][i]<mini)
                {
                    mini=matrix[row_index][i];
                }
            }
            if(mini==maxi)
            {
                ans.push_back(mini);
            }
            j++;
        }
        return ans;
    }
};
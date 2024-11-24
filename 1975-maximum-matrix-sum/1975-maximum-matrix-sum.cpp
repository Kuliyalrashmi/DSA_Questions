class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int negative=0,small_value=INT_MAX;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<0)
                {
                    negative++;
                }
                small_value=min(small_value,abs(matrix[i][j]));
            }
        }
        if(negative%2==0)
        {
            return sum;
        }
        return sum-2*small_value;
    }
};
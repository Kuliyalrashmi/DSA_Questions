class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal(numRows);
        for(int i=0;i<numRows;i++)
        {
            pascal[i]=vector<int>(i+1,1);
            for(int j=1;j<i;j++)
            {
                pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
            }
        }
        return pascal;
    }
};
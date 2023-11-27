/* 
Leetcode Question No 1727 Largest Submatrix With Rearrangements
You are given a binary matrix matrix of size m x n, 
and you are allowed to rearrange the columns of the matrix in any order.
Return the area of the largest submatrix within matrix where every element of the submatrix is 1
after reordering the columns optimally.
*/
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int max_Area=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1&&i>0)
                {
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
            vector<int>temp=matrix[i];
            sort(temp.begin(),temp.end(),greater<int>());
            for(int k=0;k<n;k++)
            {
                int base=k+1;
                int height=temp[k];
                max_Area=max(max_Area,base*height);
            }
        }
        return max_Area;
    }
};

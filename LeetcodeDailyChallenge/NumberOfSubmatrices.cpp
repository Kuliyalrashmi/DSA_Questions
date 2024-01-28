/*   28-Jan-2024
Leetcode Question no 1074 Number of Submatrices that Sum To Target
Given a matrix and a target, return the number of non-empty submatrices that sum to target.

A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.

Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different 
if they have some coordinate that is different: for example, if x1 != x1'.

*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        //Commulatiove sum of matrix row size
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int result=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                unordered_map<int,int>mp;
                mp[0]=1;
                int sum=0;
                for(int k=0;k<m;k++)
                {
                    sum+=matrix[k][j]-(i>0?matrix[k][i-1]:0);
                    if(mp.count(sum-target))
                    {
                        result+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return result;
    }
};

/* leetcode 73 Set Matrix zero*/
/*Approach -1 using two vector to store the index of rows and columns*/
void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for(int i=0;i<row.size();i++)
        {
            for(int j=0;j<col.size();j++)
            {
                if(row[i]==1||col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
/* Time Complexity=O(m*n)
  Space Complexity=O(m+n)
*/



/* Approach-2* Using a col variable */
 void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int col=1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    if(j!=0)
                    {
                        matrix[0][j]=0;
                    }
                    else 
                    {
                        col=0;
                    }
                }
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]!=0)
                {
                   if(matrix[i][0]==0||matrix[0][j]==0)
                    {
                       matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j]=0;
            }
        }
        if(col==0)
        {
            for(int j=0;j<m;j++)
            {
                matrix[j][0]=0;
            }
        }
    }

/* Time Complexity=O(m*n)
  Time complexity=O(1)
*/

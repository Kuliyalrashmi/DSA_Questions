/*  13-Dec-2023
  
Leetcode Question no 1582 Special Position In a Binary Matrix
Given an m x n binary matrix mat, return the number of special positions in mat.
A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0
(rows and columns are 0-indexed).

*/

class Solution
{
public:
    int numSpecial(vector<vector<int>> &mat)
    {
        int n = mat.size(), m = mat[0].size(), row, col, count = 0, flag = 1;
        for (int i = 0; i < n; i++)
        {
            flag = 1;
            for (int j = 0; j < m; j++)
            {
                cout << mat[i][j] << endl;
                if (mat[i][j] == 1)
                {
                    row = i;
                    col = j;
                    for (int j = 0; j < m; j++)
                    {
                        if (mat[row][j] == 1 && j != col)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    cout << flag << endl;
                    if (flag != 0)
                    {
                        int k;
                        for (k = 0; k < n; k++)
                        {
                            if (mat[k][col] == 1 && k != row)
                            {
                                break;
                            }
                        }
                        if (k == n)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};

 

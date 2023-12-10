/* 10-Dec-2023 
Leetcode Question no 867 Transpose Matrix
Given a 2D integer array matrix, return the transpose of matrix.
The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int column = matrix.size(), row= matrix[0].size();
        vector<vector<int>> result(row, vector<int>(column, 0));
        for (int j = 0; j < row; j++)
            for (int i = 0; i < column; i++)
                result[j][i] = matrix[i][j];
        return result;
    }
};

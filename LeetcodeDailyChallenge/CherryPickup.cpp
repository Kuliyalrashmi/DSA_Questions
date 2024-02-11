/*  11-Feb-2024
Leetcode Question no 1463 Cherry Pickup II
You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the 
number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
*/


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); 
        vector<vector<int>> prev(n, vector<int>(n));
        prev[0][n-1] = (n == 1) ? grid[0][0] : grid[0][0] + grid[0][n-1];
        for (int row = 1; row < m; row++) {
            vector<vector<int>> curr(n, vector<int>(n));
            for (int c1 = 0; c1 <= min(n-1, row); c1++) {      
                for (int c2 = max(0, n-1-row); c2 < n; c2++) { 
                    int prev_max = 0;
                    for (int column1 = max(0, c1 - 1); column1 <= min(n - 1, c1 + 1); column1++) {
                        for (int column2 = max(0, c2 - 1); column2 <= min(n - 1, c2 + 1); column2++) {
                             prev_max = max(prev_max, prev[column1][column2]);
                        }
                    }
                    if (c1 == c2)
                        curr[c1][c2] = prev_max + grid[row][c1];
                    else
                        curr[c1][c2] = prev_max + grid[row][c1] + grid[row][c2];
                }
            }
            prev = curr;
        }
        
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, prev[i][j]);    
            }
        }
        return res;
    }
};

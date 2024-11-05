class Solution {
public:
    int m, n;
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& t) {
        if (i >= grid.size() || j >= grid[0].size()) 
            return 0;
        if (grid[i][j] == 0)
            return 0;
        if (t[i][j] != -1)
            return t[i][j];
        int right = solve(i, j + 1, grid, t);
        int diagonal = solve(i + 1, j + 1, grid, t);
        int below = solve(i + 1, j, grid, t);
        return t[i][j] = 1 + min({right, diagonal, below});
    }
    int countSquares(vector<vector<int>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> t(m, vector<int>(n, -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += solve(i, j, grid, t);
            }
        }
        return result;
    }
};

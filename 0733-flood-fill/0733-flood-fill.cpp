class Solution {
    void dfs(int row, int col, int clr, int init, vector<vector<int>>& grid) {
        grid[row][col] = clr;
        int m = grid.size();
        int n = grid[0].size();

        if (row + 1 < m && grid[row + 1][col] == init) {
            // grid[row + 1][col] = clr;
            dfs(row + 1, col, clr, init, grid);
        }
        if (row - 1 >= 0 && grid[row - 1][col] == init) {
            // grid[row - 1][col] = clr;
            dfs(row - 1, col, clr, init, grid);
        }
        if (col + 1 < n && grid[row][col + 1] == init) {
            // grid[row][col + 1] = clr;
            dfs(row, col + 1, clr, init, grid);
        }
        if (col - 1 >= 0 && grid[row][col - 1] == init) {
            // grid[row][col - 1] = clr;
            dfs(row, col - 1, clr, init, grid);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int initColor = image[sr][sc];
        if (initColor == color) {
            return image;
        }
        vector<vector<int>> ans = image;

        dfs(sr,sc,color,initColor,ans);

        return ans;
    }
};
class Solution {
    const int M = 1e9 + 7;
    int rec(int i, int j, int dir, vector<vector<vector<int>>>& dp,
            vector<vector<int>>& grid) {
        if (i == grid.size() || j == grid[0].size()) {
            return 0;
        }

        if (i == grid.size() - 1 && j == grid[0].size() - 1) {
            return 1;
        }

        if (dp[i][j][dir] != -1) {
            return dp[i][j][dir];
        }

        if (grid[i][j] == 0) {
            int right = rec(i, j + 1, 0, dp, grid) % M;
            int down = rec(i + 1, j, 1, dp, grid) % M;

            return dp[i][j][dir] = (right + down) % M;
        }

        if (dir == 0) {
            return dp[i][j][dir] = rec(i + 1, j, 1, dp, grid) % M;
        }

        return dp[i][j][dir] = rec(i, j + 1, 0, dp, grid) % M;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(3, -1)));

        return rec(0, 0, 2, dp, grid);
    }
};
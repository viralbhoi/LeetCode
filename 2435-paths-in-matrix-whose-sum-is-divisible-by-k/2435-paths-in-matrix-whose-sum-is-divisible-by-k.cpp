const int mod = 1e9 + 7;
class Solution {
    int solve(int i, int j, int rem, vector<vector<int>>& grid, int k,
              vector<vector<vector<int>>>& dp) {
        if (dp[i][j][rem] != -1) {
            return dp[i][j][rem];
        }

        int newRem = (rem + grid[i][j]) % k;

        if (i == (grid.size() - 1) && j == (grid[0].size() - 1)) {
            return dp[i][j][rem] = (newRem == 0);
        }

        long long ways = 0;

        if (i + 1 < grid.size()) {
            ways += solve(i + 1, j, newRem, grid, k, dp);
            ways %= mod;
        }

        if (j + 1 < grid[0].size()) {
            ways += solve(i, j + 1, newRem, grid, k, dp);
            ways %= mod;
        }

        return dp[i][j][rem] = ways;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(k, -1)));

        return solve(0, 0, 0, grid, k, dp);
    }
};
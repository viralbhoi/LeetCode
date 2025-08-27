class Solution {
    int solve(int r, int c, vector<vector<int>>& m, vector<vector<int>>& dp) {
        int n = m.size();
        if (c >= n || c < 0) {
            return 1e7;
        }

        if (r == n - 1) {
            return m[r][c];
        }

        if (dp[r][c] != -1) {
            return dp[r][c];
        }

        int x = solve(r + 1, c - 1, m, dp);
        int y = solve(r + 1, c, m, dp);
        int z = solve(r + 1, c + 1, m, dp);

        return dp[r][c] = (m[r][c] + min({x, y, z}));
    }

public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[n - 1] = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int bottom_left = (j == 0) ? 1e6 : dp[i + 1][j - 1];
                int bottom = dp[i + 1][j];
                int bottom_right = (j == n - 1) ? 1e6 : dp[i + 1][j + 1];

                dp[i][j] =
                    matrix[i][j] + (int)min({bottom_left, bottom, bottom_right});
            }
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[0][i]);
        }
        return ans;
    }
};
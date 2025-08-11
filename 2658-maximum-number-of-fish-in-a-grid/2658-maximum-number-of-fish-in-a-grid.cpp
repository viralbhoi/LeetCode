class Solution {
    int dfs(int row, int col, vector<vector<int>>& vis,
            vector<vector<int>>& grid) {
        vis[row][col] = 1;
        int cnt = grid[row][col];

        int d1[] = {0, 1, 0, -1};
        int d2[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++) {
            int nr = row + d1[i];
            int nc = col + d2[i];

            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size() &&
                vis[nr][nc] == 0 && grid[nr][nc] >= 1) {
                cnt += dfs(nr, nc, vis, grid);
            }
        }

        return cnt;
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && vis[i][j] == 0) {
                    ans = max(ans, dfs(i, j, vis, grid));
                }
            }
        }
        return ans;
    }
};
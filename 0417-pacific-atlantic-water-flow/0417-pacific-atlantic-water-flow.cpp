class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = heights.size();
        int m = heights[0].size();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, m - 1, heights, atlantic);
        }

        for (int j = 0; j < m; j++) {
            dfs(0, j, heights, pacific);
            dfs(n - 1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
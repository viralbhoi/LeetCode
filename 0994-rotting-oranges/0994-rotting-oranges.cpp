class Solution {
    bool isValid(int i, int j, vector<vector<int>>& vis,
                 vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() &&
               vis[i][j] == 0 && grid[i][j];
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int time = 0;
        // store like {i,j,time};
        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j, time});
                    vis[i][j] = 2;
                }

            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                vector<int> curr = q.front();
                q.pop();

                time = max(time, curr[2]);

                for (int j = 0; j < 4; j++) {
                    int r = curr[0] + dx[j];
                    int c = curr[1] + dy[j];

                    if (isValid(r, c, vis, grid)) {
                        q.push({r, c, curr[2] + 1});
                        vis[r][c] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    return -1;
                }
            }
        }

        return time;
    }
};
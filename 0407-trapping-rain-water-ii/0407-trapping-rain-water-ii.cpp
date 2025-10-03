class Solution {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        int n = heightMap.size();
        int m = heightMap[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            vis[i][0] = 1;
            pq.push({heightMap[i][0], i, 0});

            vis[i][m - 1] = 1;
            pq.push({heightMap[i][m - 1], i, m - 1});
        }

        for (int j = 0; j < m; j++) {
            vis[0][j] = 1;
            pq.push({heightMap[0][j], 0, j});

            vis[n - 1][j] = 1;
            pq.push({heightMap[n - 1][j], n - 1, j});
        }

        int ans = 0;

        while (!pq.empty()) {
            int x = pq.top()[1];
            int y = pq.top()[2];
            int h = pq.top()[0];

            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    vis[nx][ny] == 0) {
                    ans += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), nx, ny});
                    vis[nx][ny] = 1;
                }
            }
        }

        return ans;
    }
};
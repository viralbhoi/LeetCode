class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    bool isPossible(int i, int j, int mid, vector<vector<int>>& grid,
                    vector<vector<int>>& vis) {


        if (i >= grid.size() || j >= grid.size() || i < 0 || j < 0 ||
            vis[i][j] || grid[i][j] > mid) {
            return false;
        }

        vis[i][j] = 1;

        if (i == (grid.size() - 1) && j == (grid.size() - 1)) {
            return true;
        }
        
        for (int d = 0; d < 4; d++) {
            int ni = i + dx[d];
            int nj = j + dy[d];

            if (isPossible(ni, nj, mid, grid, vis)) {
                return true;
            }
        }

        return false;
    }

public:
    // binary search on answers + dfs
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0;
        int high = n * n - 1;
        int ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;

            vector<vector<int>> vis(n, vector<int>(n, 0));

            if (isPossible(0, 0, mid, grid, vis)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
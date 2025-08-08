class Solution {
public:
    bool dfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<int>>& vis, string& word, int current_index) {
        int n = grid.size();
        int m = grid[0].size();

        if (current_index == word.size()) {
            return true;
        }
        if (!(row >= 0 && col >= 0 && row < n && col < m &&
              vis[row][col] == 0 && grid[row][col] == word[current_index])) {
            return false;
        }


        vis[row][col] = 1;

        int delta[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++) {
            int nr = row + delta[i][0];
            int nc = col + delta[i][1];

            if (dfs(nr, nc, grid, vis, word, current_index + 1))
                return true;
        }

        vis[row][col] = 0; // ✅ backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && board[i][j] == word[0]) {
                    if (dfs(i, j, board, vis, word, 0))
                        return true;
                }
            }
        }

        return false;
    }
};
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int start_row = -1, end_row = -1;
        int start_col = -1, end_col = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    if (start_row == -1) {
                        start_row = i;
                    }

                    end_row = i;

                    if (start_col == -1 || j < start_col) {
                        start_col = j;
                    }

                    if (j > end_col) {
                        end_col = j;
                    }
                }
            }
        }

        int width = (end_col - start_col + 1);
        int height = (end_row - start_row + 1);

        return width * height;
    }
};
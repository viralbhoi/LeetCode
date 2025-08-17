class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n);
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            board[i] = s;
        }

        getAns(ans, board, n, 0);

        return ans;
    }

private:
    bool isSafe(int row, int col, vector<string> &board, int n) {
        int r = row, c = col;

        while (col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            col--;
        }

        col = c;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row--;
            col--;
        }
        row = r;
        col = c;

        while (row < n && col >= 0) {
            if (board[row][col] == 'Q') {
                return false;
            }
            row++;
            col--;
        }
        return true;
    }

    void getAns(vector<vector<string>>& ans, vector<string>& board, int n,
                int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                getAns(ans, board, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
};
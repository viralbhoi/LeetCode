class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag1, flag2, flag3 = true;
        flag1 = checkRow(board);
        flag2 = checkCol(board);

        // bool temp;

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                flag3 &= checkGrid(board, i, j);
            }
        }

        return (flag1 && flag2 && flag3);
    }

    bool checkRow(vector<vector<char>>& b) {
        // int chk = 0, row = 0;

        for (int i = 0; i < 9; i++) {
            vector<int> freq(10, 0);
            for (int j = 0; j < 9; j++) {
                if (b[i][j] != '.') {
                    freq[b[i][j] - '0']++;
                    if (freq[b[i][j] - '0'] > 1) {
                        return false;
                    }
                }
            }
        }
        // row++;

        return true;
    }

    bool checkCol(vector<vector<char>>& b) {
        // int chk = 0, col = 0;

        for (int i = 0; i < 9; i++) {
            vector<int> freq(10, 0);
            for (int j = 0; j < 9; j++) {
                if (b[j][i] != '.') {
                    freq[b[j][i] - '0']++;
                    if (freq[b[j][i] - '0'] > 1) {
                        return false;
                    }
                }
            }
        }

        return true;
    }

    bool checkGrid(vector<vector<char>>& b, int row, int col) {
        // int chk = 0, col = 0;
        vector<int> freq(10, 0);
        for (int i = row; i < row + 3; i++) {
            for (int j = col; j < col + 3; j++) {
                if (b[i][j] != '.') {
                    freq[b[i][j] - '0']++;
                }
            }
        }

        for (auto ele : freq) {
            if (ele > 1)
                return false;
        }
        return true;
    }
};
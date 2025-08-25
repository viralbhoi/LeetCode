class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int i = 0;
        int j = 0;

        bool down = false;

        vector<int> ans;

        while (ans.size() < m * n) {
            if (down) {
                while (i < m && j >= 0) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }

                if (i >= m && j < 0) {
                    i = m - 1;
                    j = 1;
                } else if (j == -1) {
                    j = 0;
                } else {
                    i = m - 1;
                    j += 2;
                }
            } else {
                while (j < n && i >= 0) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }

                if (i < 0 && j >= n) {
                    i = 1;
                    j = n - 1;
                } else if (j == n) {
                    j = n - 1;
                    i += 2;
                } else {
                    i = 0;
                }
            }

            down = !down;
        }

        return ans;
    }
};
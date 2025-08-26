class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int max_diag = -1, max_area = -1;

        for (auto dim : dimensions) {
            int l = dim[0];
            int b = dim[1];

            int diag = l * l + b * b;

            if (diag > max_diag) {
                max_diag = diag;
                max_area = l * b;
            } else if (diag == max_diag) {
                max_area = max(max_area, l * b);
            }
        }

        return max_area;
    }
};
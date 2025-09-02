class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> A = points[i];

            for (int j = 0; j < n; j++) {
                if (j == i) {
                    continue;
                }
                vector<int> B = points[j];

                if (A[0] > B[0] || A[1] < B[1]) {
                    continue;
                }

                bool possible = true;

                for (int k = 0; k < n; k++) {

                    if (i == k || j == k) {
                        continue;
                    }
                    vector<int> C = points[k];

                    if ((C[0] >= A[0] && C[0] <= B[0]) &&
                        (C[1] <= A[1] && C[1] >= B[1])) {
                        possible = false;
                        break;
                    }
                }

                if (possible) {
                    ans++;
                };
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans = INT_MAX;
        int n = matrix.size();

        vector<int> dp;
        

        dp = matrix[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            vector<int> curr(n,1e9);
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (j != k) {
                        curr[j] = min(curr[j], matrix[i][j] + dp[k]);
                    }
                }
            }
            dp = curr;
        }

        for (int i = 0; i < n; i++) {
            ans = min(ans, dp[i]);
        }
        return ans;
    }
};
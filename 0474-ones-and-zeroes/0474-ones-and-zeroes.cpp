class Solution {
    vector<int> ones, zeros;

    int rec(int idx, int zero, int one, int m, int n,
            vector<vector<vector<int>>>& dp) {

        if (one > n || zero > m) {
            return INT_MIN;
        }

        if (idx == ones.size()) {
            return 0;
        }

        if (dp[idx][one][zero] != -1) {
            return dp[idx][one][zero];
        }

        int take = 1 + rec(idx + 1, zero + zeros[idx], one + ones[idx], m, n, dp);
        int notTake = rec(idx + 1, zero, one, m, n, dp);

        return dp[idx][one][zero] = max(take, notTake);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        for (auto it : strs) {
            ones.push_back(count(it.begin(), it.end(), '1'));
            zeros.push_back(it.size() - ones.back());
        }

        vector<vector<vector<int>>> dp(
            101, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));

        return rec(0, 0, 0, m, n, dp);
    }
};
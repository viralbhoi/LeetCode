class Solution {
    const int inf = 1e9;

    int rec(int idx, vector<int>& coins, vector<vector<int>>& dp, int amount) {
        if (idx == coins.size() || amount == 0) {
            return (amount == 0) ? 0 : inf;
        }

        if (dp[idx][amount] != -1) {
            return dp[idx][amount];
        }

        int take = inf, notTake = inf;

        if (amount >= coins[idx]) {
            take = 1 + rec(idx, coins, dp, amount - coins[idx]);
        }

        notTake = rec(idx + 1, coins, dp, amount);

        return dp[idx][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));

        int ans = rec(0, coins, dp, amount);

        if (ans >= inf) {
            ans = -1;
        }

        return ans;
    }
};
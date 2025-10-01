class Solution {
    int LIS(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i][j + 1] != -1) {
            return dp[i][j + 1];
        }

        int take = 0;
        int notTake = LIS(nums, i + 1, j, dp);

        if (j == -1 || nums[i] > nums[j]) {
            take = 1 + LIS(nums, i + 1, i, dp);
        }

        return dp[i][j + 1] = max(take, notTake);
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size(), -1));

        return LIS(nums, 0, -1, dp);
    }
};
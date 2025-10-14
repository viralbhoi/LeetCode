class Solution {
    bool isIncreasing(int start, int k, vector<int>& nums) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i + 1] <= nums[i])
                return false;
        }
        return true;
    }

public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (k == 1 && n > 1) {
            return true;
        }

        for (int i = 0; i + 2 * k <= n; i++) {
            if (isIncreasing(i, k, nums) && isIncreasing(i + k, k, nums)) {
                return true;
            }
        }

        return false;
    }
};
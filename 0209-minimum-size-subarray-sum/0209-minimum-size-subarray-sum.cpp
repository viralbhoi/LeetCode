class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int n = nums.size();
        int l = 0;
        int r = 0;

        int sum = 0;

        while (r < n) {
            sum += nums[r];

            while (l <= r && sum >= target) {
                min_len = min(min_len, r - l + 1);
                sum -= nums[l];
                l++;
            }

            r++;
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};
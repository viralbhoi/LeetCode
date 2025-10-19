class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;
        vector<bool> inc(n, false), dec(n, false);

        inc[0] = true;

        for (int i = 1; i < n; i++) {
            inc[i] = inc[i - 1] && nums[i] > nums[i - 1];
        }

        dec[n - 1] = true;

        for (int i = n - 2; i >= 0; i--) {
            dec[i] = dec[i + 1] && nums[i] > nums[i + 1];
        }

        vector<long long> prefix(n, 0ll);

        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < n - 1; i++) {
            if (inc[i] && dec[i + 1]) {
                ans = min(ans, llabs(prefix[i] - prefix[n - 1] + prefix[i]));
            }
        }

        return ans == LLONG_MAX ? -1 : ans;
    }
};
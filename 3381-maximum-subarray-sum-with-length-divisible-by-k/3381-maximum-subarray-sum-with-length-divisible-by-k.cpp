class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long prefix = 0;
        long long ans = LLONG_MIN;

        vector<long long> mini(k, LLONG_MAX / 2);
        mini[k - 1] = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix += nums[i];
            ans = max(ans, prefix - mini[i % k]);
            mini[i % k] = min(mini[i % k], prefix);
        }

        return ans;
    }
};
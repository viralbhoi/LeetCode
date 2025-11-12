class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt1 = 0;
        int n = nums.size();
        int g = 0;

        for (auto& it : nums) {
            cnt1 += it == 1;
            g = __gcd(g, it);
        }

        if (g > 1) {
            return -1;
        }

        if (cnt1) {
            return n - cnt1;
        }

        int min_len = n;

        for (int i = 0; i < n; i++) {
            g = 0;
            for (int j = i; j < n; j++) {
                g = __gcd(nums[j], g);

                if (g == 1) {
                    min_len = min(j - i, min_len);
                    break;
                }
            }
        }

        return n + min_len - 1;
    }
};
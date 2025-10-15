class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> pre(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                pre[i] = pre[i - 1] + 1;
            }
        }

        int ans = 1;
        int left = 1, right = n / 2;

        while (left <= right) {
            int mid = (left + right) / 2;
            bool found = false;
            for (int i = 0; i + 2 * mid < n; i++) {
                if (pre[i + mid] >= mid && pre[i + 2 * mid] >= mid) {
                    found = true;
                    break;
                }
            }

            if (found) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};
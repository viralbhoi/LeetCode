class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int find = nums[i] + nums[j];

                int idx = lower_bound(nums.begin() + j + 1, nums.end(), find) -
                          nums.begin();

                ans += idx - (j + 1);
            }
        }

        return ans;
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = 2;
        int curr_len = 2;

        for (int i = 2; i < nums.size(); i++) {
            int need = nums[i - 1] + nums[i - 2];

            if (need == nums[i]) {
                curr_len++;
            } else {
                len = max(len, curr_len);
                curr_len = 2;
            }
        }

        len = max(len, curr_len);

        return len;
    }
};
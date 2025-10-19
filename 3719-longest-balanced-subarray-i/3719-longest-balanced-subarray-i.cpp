class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int max_len = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            map<int, int> odd;
            map<int, int> even;
            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0) {
                    even[nums[j]]++;
                } else {
                    odd[nums[j]]++;
                }

                if (odd.size() == even.size()) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> mp(101, 0);
        int max_freq = 0;

        for (auto it : nums) {
            mp[it]++;
            max_freq = max(max_freq, mp[it]);
        }

        int ans = 0;

        for (auto it : mp) {
            if (it == max_freq) {
                ans += it;
            }
        }

        return ans;
    }
};
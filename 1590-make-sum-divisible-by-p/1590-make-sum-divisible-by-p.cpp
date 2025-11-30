class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);

        if (sum % p == 0) {
            return 0;
        }
        int n = nums.size();
        int need_to_remove = sum % p;
        int min_len = n;
        map<int,int> mp;
        long long prefix = 0;
        mp[0] = -1;
        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            int target = (prefix - need_to_remove + p) % p;

            if (mp.find(target) != mp.end()) {
                min_len = min(min_len, i - mp[target]);
            }

            mp[prefix % p] = i;
        }

        return min_len == n ? -1 : min_len;
    }
};
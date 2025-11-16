class Solution {
    const int MOD = 1e9 + 7;

public:
    int numSub(string s) {
        int seg = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                seg++;
            } else {
                ans = (0LL + ans + (1ll * seg * (seg + 1)) / 2) % MOD;
                seg = 0;
            }
        }
        ans = (0LL + ans + (1ll * seg * (seg + 1)) / 2) % MOD;

        return ans;
    }
};
class Solution {
    const int MOD = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {

        vector<int> knows(n + 1, 0);
        int ans = 0;

        knows[1] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = i + delay; j <= n && j < i + forget; j++) {
                knows[j] = (knows[j] + knows[i])% MOD;
            }
        }

        for(int i = n - forget + 1; i<= n;i++){
            ans = (ans + knows[i]) % MOD;
        }

        return ans;
    }
};
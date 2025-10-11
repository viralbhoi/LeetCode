class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> mp;

        for (auto p : power) {
            mp[p]++;
        }

        vector<pair<long long, long long>> damageSpells;

        for (auto& it : mp) {
            damageSpells.push_back({it.first, 1LL * it.first * it.second});
        }

        sort(damageSpells.begin(), damageSpells.end());
        int n = damageSpells.size();

        vector<long long> dp(n,0);
        dp[0] = damageSpells[0].second;

        for (int i = 1; i < n; i++) {
            int j = i - 1;

            while (j >= 0 &&
                   damageSpells[i].first - 2 <= damageSpells[j].first) {
                j--;
            }

            long long notTake = dp[i - 1];
            long long take = damageSpells[i].second + (j >= 0 ? dp[j] : 0);

            dp[i] = max(take, notTake);
        }

        return dp[n - 1];
    }
};
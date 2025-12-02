class Solution {
public:
    const int MOD = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(auto &p : points){
            mp[p[1]]++;
        }
        long long ans = 0;
        long long totalEdge = 0;
        for(auto &[y, cnt] : mp){
            long long edge = 1ll * (cnt) * (cnt - 1)/2;

            ans += edge * totalEdge;
            totalEdge += edge;

            ans %= MOD;
        }

        return ans;
    }
};
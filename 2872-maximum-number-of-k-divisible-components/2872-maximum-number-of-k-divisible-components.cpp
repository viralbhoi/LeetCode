class Solution {
    int dfs(int node, int par, vector<vector<int>>& adj, vector<int>& val,
            int k, int& ans) {
        int sum = val[node] % k;

        for (auto nd : adj[node]) {
            if (nd != par) {
                sum = (sum + dfs(nd, node, adj, val, k, ans)) % k;
            }
        }

        if (sum == 0) {
            ans++;
        }

        return sum;
    }

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 0;

        dfs(0, -1, adj, values, k, ans);

        return ans;
    }
};
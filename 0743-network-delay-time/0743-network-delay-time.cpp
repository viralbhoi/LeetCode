class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nd : adj[node]) {
                int neighbourTime = nd.second;
                int neighbour = nd.first;

                if (dist[neighbour] > time + neighbourTime) {
                    dist[neighbour] = time + neighbourTime;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }

        int ans = INT_MIN;

        for (int i = 1; i <= n; i++) {
            ans = max(ans, dist[i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
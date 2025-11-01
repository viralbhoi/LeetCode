class Solution {
    struct node {
        int diff;
        int r;
        int c;

        node(int diff, int r, int c) {
            this->diff = diff;
            this->r = r;
            this->c = c;
        }

        bool operator>(const node& other) const { return diff > other.diff; }
    };

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<node, vector<node>, greater<node>> pq;

        pq.push(node(0, 0, 0));
        effort[0][0] = 0;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};


        while (!pq.empty()) {
            int diff = pq.top().diff;
            int r = pq.top().r;
            int c = pq.top().c;

            pq.pop();

            if (r == n - 1 && c == m - 1) {
                return diff;
            }

            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int newDiff =
                        max(diff, abs(heights[nr][nc] - heights[r][c]));
                    if (newDiff < effort[nr][nc]) {
                        effort[nr][nc] = newDiff;
                        pq.push(node(newDiff, nr, nc));
                    }
                }
            }
        }

        return -1; 
    }
};
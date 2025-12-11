class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxX(n + 1, INT_MIN);
        vector<int> maxY(n + 1, INT_MIN);
        vector<int> minX(n + 1, INT_MAX);
        vector<int> minY(n + 1, INT_MAX);

        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            minX[y] = min(x, minX[y]);
            minY[x] = min(y, minY[x]);
            maxX[y] = max(x, maxX[y]);
            maxY[x] = max(y, maxY[x]);
        }

        int ans = 0;

        for (auto& building : buildings) {
            int x = building[0];
            int y = building[1];

            bool xCover = (x > minX[y] && x < maxX[y]);
            bool yCover = (y > minY[x] && y < maxY[x]);

            ans += (xCover && yCover);
        }

        return ans;
    }
};
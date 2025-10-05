class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxAns = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int samePoints = 0;
            map<pair<int, int>, int> mp;
            int currMax = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }

                int dx = points[i][0] - points[j][0];
                int dy = points[i][1] - points[j][1];

                if (dx == 0 && dy == 0) {
                    samePoints++;
                    continue;
                }

                int g = __gcd(dx, dy);

                dx /= g;
                dy /= g;

                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = 1;
                } else if (dy == 0) {
                    dx = 1;
                }

                mp[{dx, dy}]++;

                currMax = max(currMax, mp[{dx, dy}]);
            }

            maxAns = max(maxAns, samePoints + currMax + 1);
        }

        return maxAns;
    }
};
class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> pref(n + 1, vector<int>(n + 1));

        for (auto& q : queries) {
            pref[q[0]][q[1]]++;
            pref[q[2] + 1][q[1]]--;
            pref[q[0]][q[3] + 1]--;
            pref[q[2] + 1][q[3] + 1]++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int left = 0, up = 0, daig = 0;
                if (i != 0)
                    up = pref[i - 1][j];

                if (j != 0)
                    left = pref[i][j - 1];

                if (i != 0 && j != 0)
                    daig = pref[i - 1][j - 1];

                pref[i][j] += left + up - daig;
            }
        }

        for (int i = 0; i < n; i++) {
            pref[i].pop_back();
        }

        pref.pop_back();

        return pref;
    }
};
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
             });

        int max = -1;
        int sec_max = -1;

        int ans = 0;

        for (auto &interval : intervals) {
            int start = interval[0];
            int end = interval[1];

            if (start > max) {
                sec_max = end - 1;
                max = end;
                ans += 2;
            } else if (start > sec_max) {
                sec_max = max;
                max = end;
                ans += 1;
            }
        }

        return ans;
    }
};
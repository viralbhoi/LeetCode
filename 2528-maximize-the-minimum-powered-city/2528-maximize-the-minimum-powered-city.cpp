class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> diff(n + 1);

        for (int i = 0; i < n; i++) {
            int l = max(0, i - r);
            int ri = min(n - 1, i + r);
            diff[l] += stations[i];
            diff[ri + 1] -= stations[i];
        }

        vector<long long> pre(n);
        pre[0] = diff[0];
        for (int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + diff[i];

        long long low = *min_element(pre.begin(), pre.end());
        long long high = *max_element(pre.begin(), pre.end()) + k;

        auto check = [&](long long mid) -> bool {
            vector<long long> temp(n + 1, 0);
            long long cur = 0, cnt = 0;
            for (int i = 0; i < n; ++i) {
                cur += temp[i];
                long long val = pre[i] + cur;
                if (val < mid) {
                    long long need = mid - val;
                    cnt += need;
                    if (cnt > k) return false;
                    cur += need;
                    if (i + 2 * r + 1 < n)
                        temp[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid))
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

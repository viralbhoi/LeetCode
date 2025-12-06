class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2,
                        int k) {
        int n = technique1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = technique2[i] - technique1[i];
        }

        sort(diff.begin(), diff.end());
        sort(technique1.begin(), technique1.end());

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans += technique1[i];
        }

        for (int i = k; i < n; i++) {
            ans += max(technique1[i], technique1[i] + diff[i]);
        }

        return ans;
    }
};
class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;

        for (auto& it : queries) {
            long long start = it[0], end = it[1];

            long long exponent = 1;
            int base = 0;
            while (exponent * 4 <= start) {
                exponent *= 4;
                base++;
            }

            long long sumLevels = 0;
            while (start <= end) {
                long long blockEnd = exponent * 4 - 1;
                long long L = max(start, exponent);
                long long R = min(end, blockEnd);

                if (L <= R) {
                    long long len = R - L + 1;
                    sumLevels += len * (base + 1);
                }

                exponent *= 4;
                base++;
                start = blockEnd + 1;
            }

            ans += (sumLevels + 1) / 2;
        }

        return ans;
    }
};
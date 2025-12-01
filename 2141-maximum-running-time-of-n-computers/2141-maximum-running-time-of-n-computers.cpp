class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long right = accumulate(batteries.begin(), batteries.end(), 0ll);
        long long left = 0;
        right /= n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long power = 0;

            for (auto& b : batteries)
                power += min(1ll * b, mid);

            if (power >= mid * n)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return right;
    }
};
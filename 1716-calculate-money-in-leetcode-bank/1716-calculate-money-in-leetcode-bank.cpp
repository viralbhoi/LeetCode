class Solution {
public:
    int totalMoney(int n) {
        int mondays = (n + 6) / 7;

        int ans = 0;

        for (int i = 0; i < mondays - 1; i++) {
            ans += ((7 + i) * (7 + i + 1)) / 2 - ((i + 1) * i) / 2;
        }

        for (int i = 0; i < n % 7; i++) {
            ans += mondays + i;
        }

        return ans;
    }
};
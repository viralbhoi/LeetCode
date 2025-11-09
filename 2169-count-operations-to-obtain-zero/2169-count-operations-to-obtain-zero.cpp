class Solution {
public:
    int countOperations(int num1, int num2) {
        int ans = 0;
        int a = max(num1, num2);
        int b = min(num1, num2);

        while (a != 0 && b != 0) {
            if (a >= b) {
                ans += a / b;
                a %= b;
            } else {
                ans += b / a;
                b %= a;
            }

            if (b > a) {
                swap(a, b);
            }
        }

        return ans;
    }
};
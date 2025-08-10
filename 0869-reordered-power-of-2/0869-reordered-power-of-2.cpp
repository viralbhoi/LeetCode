class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string num = to_string(n);
        sort(num.begin(), num.end());

        for (int i = 0; i < 31; i++) {
            int powOf2 = (1 << i);

            string num1 = to_string(powOf2);
            sort(num1.begin(), num1.end());
            if (num == num1) {
                return true;
            }
        }

        return false;
    }
};
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";

        if (numerator == 0) {
            return "0";
        }

        if (1ll * numerator * denominator < 0) {
            ans += "-";
        }

        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        ans += to_string(n / d);

        long long rem = n % d;

        if (rem == 0) {
            return ans;
        }

        ans += ".";

        map<long long, int> mp;

        while (rem != 0) {
            if (mp.count(rem)) {
                ans.insert(mp[rem], "(");
                ans += ")";
                break;
            }

            mp[rem] = ans.size();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};
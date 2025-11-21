class Solution {
public:
    int countPalindromicSubsequence(string s) {
        set<char> taken;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (taken.find(s[i]) != taken.end()) {
                continue;
            }
            int j = n - 1;

            while (j > i + 1 && s[j] != s[i]) {
                j--;
            }

            if (s[j] != s[i]) {
                continue;
            } else {
                set<char> freq;
                taken.insert(s[i]);
                for (int k = i + 1; k < j ; k++) {
                    freq.insert(s[k]);
                }

                ans += freq.size();
            }
        }

        return ans;
    }
};
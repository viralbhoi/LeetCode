class Solution {
    bool allSame(vector<int>& cnt) {
    int val = -1;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue; 
        if (val == -1) val = cnt[i];
        else if (cnt[i] != val) return false;
    }
    return true;
}


public:
    int longestBalanced(string s) {
        int max_len = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> cnt(26, 0);
            for (int j = i; j < n; j++) {
                cnt[s[j] - 'a']++;

                if (allSame(cnt)) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }
        return max_len;
    }
};
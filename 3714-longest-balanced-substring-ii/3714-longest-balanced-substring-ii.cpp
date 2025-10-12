class Solution {
    void findSingleCharMax(string& s, int& maxi) {
        int max_len = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) {
                maxi = max(maxi, max_len);
                max_len = 1;
            } else {
                max_len++;
            }
        }

        maxi = max(maxi, max_len);
    }

    void findDoubleCharMax(string& s, char x, char y, int& maxi) {
        int sum = 0;
        map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == x) {
                sum++;
            } else if (s[i] == y) {
                sum--;
            } else {
                mp.clear();
                mp[0] = i; // same thing i do as mp[0] = -1 in start
                sum = 0;
            }

            if (mp.find(sum) != mp.end()) {
                maxi = max(maxi, i - mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
    }

    void findAllCharMax(string& s, int& maxi) {
        map<pair<int, int>, int> mp;

        mp[{0, 0}] = -1;

        vector<int> cnt(3, 0);

        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;

            int cntAB = cnt[0] - cnt[1];
            int cntAC = cnt[0] - cnt[2];

            if (mp.find({cntAB, cntAC}) != mp.end()) {
                maxi = max(maxi, i - mp[{cntAB, cntAC}]);
            } else {
                mp[{cntAB, cntAC}] = i;
            }
        }
    }

public:
    int longestBalanced(string s) {
        int maxi = 0;

        findSingleCharMax(s, maxi);

        findDoubleCharMax(s, 'a', 'b', maxi);
        findDoubleCharMax(s, 'a', 'c', maxi);
        findDoubleCharMax(s, 'b', 'c', maxi);

        findAllCharMax(s, maxi);

        return maxi;
    }
};
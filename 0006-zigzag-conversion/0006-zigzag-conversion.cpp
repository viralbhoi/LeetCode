class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> mat(numRows);

        int idx = 0;
        int i = 0;
        int c = 1;
        while (idx < s.size()) {
            mat[i] += s[idx++];

            if (i == 0) {
                c = 1;
            }
            if (i == numRows - 1) {
                c = -1;
            }
            i += c;
        }

        string ans = "";

        for (auto it : mat) {
            ans += it;
        }

        return ans;
    }
};
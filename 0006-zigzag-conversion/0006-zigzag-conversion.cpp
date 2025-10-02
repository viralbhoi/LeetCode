class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> mat(1001, vector<char>(1001, '*'));

        bool up = false;

        int idx = 0;
        int j = 0;

        while (idx < s.size()) {
            if (up == false) {
                for (int i = 0; i < numRows; i++) {
                    if(idx == s.size()){
                        break;
                    }
                    mat[i][j] = s[idx++];
                }
                j++;
            } else {
                for (int i = numRows - 2; i > 0; i--) {
                    if(idx == s.size()){
                        break;
                    }
                    mat[i][j++] = s[idx++];
                }
            }
            up = !up;
        }
        string ans = "";

        for (int i = 0; i < numRows; i++) {
            for (auto it : mat[i]) {
                if (it != '*') {
                    ans += it;
                }
            }
        }

        return ans;
    }
};
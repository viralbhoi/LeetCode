class Solution {
    void addParenthesis(vector<string>& ans, int n, int open, int close,
                        string temp) {
        if (temp.size() == 2 * n) {
            ans.push_back(temp);
            return;
        }

        if (open < n) {
            addParenthesis(ans, n, open + 1, close, temp + '(');
        }

        if (close < open) {
            addParenthesis(ans, n, open, close + 1, temp + ')');
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        addParenthesis(ans, n, 0, 0, "");

        return ans;
    }
};
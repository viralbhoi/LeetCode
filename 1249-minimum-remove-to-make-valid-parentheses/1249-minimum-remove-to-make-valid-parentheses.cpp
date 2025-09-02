class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int openCnt = 0;
        int closeCnt = 0;

        stack<char> st;

        string ans = "";

        for (auto ch : s) {
            if (ch == '(') {
                openCnt++;
            } else if (ch == ')') {
                closeCnt++;
            }

            if (ch != ')') {
                st.push(ch);
            } else {
                if (closeCnt <= openCnt) {
                    st.push(ch);
                } else {
                    closeCnt--;
                }
            }
        }

        openCnt -= min(openCnt, closeCnt);

        while (!st.empty()) {
            char ch = st.top();
            st.pop();

            if (ch != '(') {
                ans = ch + ans;
            } else if (openCnt) {
                openCnt--;
            } else {
                ans = ch + ans;
            }
        }

        return ans;
    }
};
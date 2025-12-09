class Solution {
    bool isOperator(string s) {
        return s == "-" || s == "+" || s == "*" || s == "/";
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto t : tokens) {
            if (isOperator(t)) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int res = 0;
                if (t == "+") {
                    st.push(a + b);
                } else if (t == "-") {
                    st.push(a - b);
                } else if (t == "*") {
                    st.push(a * b);
                } else {
                    st.push(int((1.0 * a) / b));
                }
            } else {
                st.push(stoi(t));
            }
        }

        return st.top();
    }
};
class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        for (auto num : nums) {
            if (st.empty()) {
                st.push(num);
            } else {
                while (!st.empty() && __gcd(st.top(), num) > 1) {
                    int num2 = st.top();
                    st.pop();

                    num = (1ll *num * num2) / (__gcd(num2, num));
                }
                st.push(num);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";

        for (int i = 2; i < num.size(); i++) {
            if (num[i] == num[i - 1] && num[i] == num[i - 2]) {
                string temp = "";
                temp += num[i - 2];
                temp += num[i - 1];
                temp += num[i];
                ans = max(ans, temp);
            }
        }

        return ans;
    }
};
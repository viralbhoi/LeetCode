class Solution {
public:
    string lexSmallest(string s) {
        string ans = s;
        string temp = s;

        for (int i = 0; i <= s.size(); i++) {
            reverse(temp.begin(), temp.begin() + i);

            ans = min(ans, temp);
            temp = s;

            reverse(temp.end() - i, temp.end());
            ans = min(ans, temp);
            temp = s;
        }

        return ans;
    }
};
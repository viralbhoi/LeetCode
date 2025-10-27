class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ones;
        int cnt = 0;
        int prev = 0;
        int ans = 0;
        for (auto b : bank) {
            cnt  = 0;
            for (auto c : b) {
                cnt += (c - '0');
            }

            if (cnt > 0) {
                ans += prev * cnt;
                prev = cnt;
            }
        }

        return ans;
    }
};
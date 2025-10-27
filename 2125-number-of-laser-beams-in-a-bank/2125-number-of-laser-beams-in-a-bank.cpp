class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> ones;

        for (auto b : bank) {
            int temp = 0;
            for (auto c : b) {
                temp += (c - '0');
            }

            if (temp > 0) {
                ones.push_back(temp);
            }
        }

        int ans = 0;

        if(!ones.size()){
            return ans;
        }

        for (int i = 0; i < ones.size() - 1; i++) {
            ans += ones[i] * ones[i + 1];
        }

        return ans;
    }
};
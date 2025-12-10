class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int mini = *min_element(complexity.begin() + 1, complexity.end());

        if (mini <= complexity[0]) {
            return 0;
        }

        long long ans = 1;
        int mod = 1e9 + 7;

        for (int i = 1; i < complexity.size(); i++) {
            ans = (ans * i) % mod;
        }

        return ans;
    }
};
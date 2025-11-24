class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int pre = 0;

        for (auto& num : nums) {
            pre = (2 * pre + num) % 5;
            ans.push_back(pre == 0);
        }

        return ans;
    }
};
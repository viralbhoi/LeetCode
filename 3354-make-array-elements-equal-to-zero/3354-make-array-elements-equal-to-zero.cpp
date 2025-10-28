class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int lsum = 0;
        int rsum = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0;

        for (auto& num : nums) {

            lsum += num;
            rsum -= num;
            
            if (num != 0) {
                continue;
            }

            if (lsum == rsum) {
                ans++;
            }

            if (abs(lsum - rsum) <= 1) {
                ans++;
            }
        }

        return ans;
    }
};
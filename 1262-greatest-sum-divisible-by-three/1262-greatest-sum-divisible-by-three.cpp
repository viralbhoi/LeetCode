class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> mod1, mod2;

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += nums[i];
            if (nums[i] % 3 == 1 && mod1.size() < 2) {
                mod1.push_back(nums[i]);
            } else if (nums[i] % 3 == 2 && mod2.size() < 2) {
                mod2.push_back(nums[i]);
            }
        }

        if (ans % 3 == 0) {
            return ans;
        }

        if (ans % 3 == 1) {
            int temp = ans;
            int del1 = 0;
            int del2 = 0;

            if (mod1.size() > 0) {
                del1 = mod1[0];
            }

            if (mod2.size() > 1) {
                del2 = mod2[0] + mod2[1];
            }

            ans = max(ans - (del1 == 0 ? ans : del1),
                      ans - (del2 == 0 ? ans : del2));
        }else{
            int temp = ans;
            int del1 = 0;
            int del2 = 0;

            if (mod2.size() > 0) {
                del2 = mod2[0];
            }

            if (mod1.size() > 1) {
                del1 = mod1[0] + mod1[1];
            }

            ans = max(ans - (del1 == 0 ? ans : del1),
                      ans - (del2 == 0 ? ans : del2));
        }

        return ans;
    }
};
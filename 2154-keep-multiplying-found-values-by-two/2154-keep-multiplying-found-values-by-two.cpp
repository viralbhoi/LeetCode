class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int idx = -1;
        while (1) {
            idx = -1;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == original) {
                    idx = i;
                    original = original * 2;
                    break;
                }
            }

            if (idx == -1) {
                break;
            }
        }
        return original;
    }
};
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> temp(nums.size());

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 0; j < nums.size() - 1 - i; j++) {
                temp[j] = (nums[j] + nums[j+1])%10;
            }

            nums = temp;
        }

        return nums[0];
    }
};
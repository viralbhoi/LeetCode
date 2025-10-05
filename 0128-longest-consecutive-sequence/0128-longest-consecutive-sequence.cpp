class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ls = 0;
        int cs = 1;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]){
                continue;
            }
            if (nums[i] != nums[i - 1] + 1) {
                ls = max(ls, cs);
                cs = 1;
            } else {
                cs++;
            }
        }

        ls = max(ls, cs);

        return ls;
    }
};
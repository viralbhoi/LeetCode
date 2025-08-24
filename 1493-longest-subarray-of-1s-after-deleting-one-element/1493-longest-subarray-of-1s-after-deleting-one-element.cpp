class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, r = 0;

        int cnt_zero = 0;

        int max_len = 0;

        for(r=0;r<nums.size();r++){
            if(nums[r] == 0){
                cnt_zero++;
            }

            while(l < r && cnt_zero > 1){
                cnt_zero -= nums[l] == 0;
                l++;
            }

            max_len = max (max_len, r-l);
        }

        return max_len;
    }
};
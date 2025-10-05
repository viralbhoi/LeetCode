class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xrr = 0;

        bool allZero = true;

        for(auto num : nums){
            if(num != 0){
                allZero = false;
            }

            xrr ^= num;
        }

        if(allZero){
            return 0;
        }

        if(xrr){
            return nums.size();
        }

        return nums.size() - 1;
    }
};
class Solution {
public:
    int alternatingSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            ans += i % 2 == 0 ? nums[i] : -nums[i];
        }

        return ans;
    }
};
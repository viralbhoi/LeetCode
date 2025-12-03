class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_ops = 0;
        int max_ele = *max_element(nums.begin(),nums.end());

        for(auto &num : nums){
            min_ops += max_ele - num;
        }

        return min_ops;
    }
};
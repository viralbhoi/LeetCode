class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int ori = 0;

        for(auto n : nums){
            if(!(n & 1)){
                ori |= n;
            }
        }

        return ori;
    }
};
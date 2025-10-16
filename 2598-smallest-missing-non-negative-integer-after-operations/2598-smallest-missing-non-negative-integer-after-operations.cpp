class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;

        for(auto num : nums){
            mp[((num % value) + value) % value] ++;
        }

        int mex = 0;

        while(mp[mex % value] --){
            mex ++;
        }

        return mex;
    }
};
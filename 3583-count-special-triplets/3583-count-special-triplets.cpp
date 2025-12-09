class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        map<int,int> freq, prev;
        const int MOD = 1e9 + 7;
        for(auto &num : nums){
            freq[num]++;
        }

        int ans = 0;

        for(auto &num : nums){
            freq[num] --;
            int temp = num * 2;

            ans = (ans + prev[temp] * freq[temp]) % MOD;
            prev[num]++;
        }

        return ans;
    }
};
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int> mp;

        for(auto x : nums){
            mp[x]++;
        }

        int ans = 0;

        for(auto p : mp){
            if(p.second % k == 0){
                ans += p.first * p.second;
            }
        }

        return ans;
    }
};
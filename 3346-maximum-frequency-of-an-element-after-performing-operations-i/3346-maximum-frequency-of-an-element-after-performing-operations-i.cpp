class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        unordered_map<int, int> freq;

        for (auto a : nums) {
            freq[a]++;
        }
        sort(nums.begin(), nums.end());
        int max_freq = 0;
        int max_freq_ele = nums[nums.size() / 2];
        for (auto p : freq) {
            if (p.second > max_freq) {
                max_freq = p.second;
                max_freq_ele = p.first;
            }
        }
        int ans = 0;
        for (auto a : nums) {
            if(a==max_freq_ele){
                ans++;
            }
            else if (abs(a - max_freq_ele) <= k) {
                ans++;
                numOperations--;
            }
            if(!numOperations){
                break;
            }
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            multimap<pair<int, int>,int, greater<pair<int,int>>> fL;  
            vector<int> freq(51,0);  
            

            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }

            for (int val = 0; val <= 50; val++) {
                if (freq[val] != 0) {
                    fL.insert({{freq[val], val}, val});
                }
            }


            int cnt = 0;
            long sum = 0;
            for (auto p : fL) {
                cnt++;
                if (cnt > x) break;
                sum += p.first.first * p.first.second;
            }
            ans.push_back(sum);
        }

        return ans;
    }
};
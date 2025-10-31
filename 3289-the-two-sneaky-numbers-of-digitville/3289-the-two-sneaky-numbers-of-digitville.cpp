class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map <int,int> mp;

        for(auto e:nums){
            mp[e]++;
        }

        vector<int> ans;

        for(auto p:mp){
            if(p.second>1){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};
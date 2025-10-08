class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        int n = potions.size();

        for(auto spell : spells){
            long long x = (success + spell - 1)/ spell;

            int it = lower_bound(potions.begin(),potions.end(),x) - potions.begin();

            ans.push_back(n - it);
        }

        return ans;
    }
};
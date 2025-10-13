class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<vector<int>> freq(words.size(), vector<int>(26));

        for (int i = 0; i < words.size(); i++) {
            for (auto ch : words[i]) {
                freq[i][ch - 'a']++;
            }
        }

        vector<string> ans;
        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); i++) {
            if (freq[i] != freq[i - 1]) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
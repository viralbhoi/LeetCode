class Solution {
    bool isValid(string code, bool active, string cat) {
        if (active == false) {
            return active;
        }

        if (cat != "electronics" && cat != "grocery" && cat != "pharmacy" &&
            cat != "restaurant") {
            return false;
        }

        for (auto& c : code) {
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
                  (c >= 'A' && c <= 'Z') || (c == '_'))) {
                return false;
            }
        }

        return code.size() != 0;
    }

public:
    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        int n = code.size();

        map < string, vector<string>> mp;

        for (int i = 0; i < n; i++) {
            if (isValid(code[i], isActive[i], businessLine[i])) {
                mp[businessLine[i]].push_back(code[i]);
            }
        }

        vector<string> ans;

        for (auto& p : mp) {
            sort(p.second.begin(), p.second.end());

            ans.insert(ans.end(), p.second.begin(), p.second.end());
        }

        return ans;
    }
};
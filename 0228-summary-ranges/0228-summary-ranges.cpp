class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        vector<string> ans;

        int i = 1;
        int start = nums[0];
        int cur = nums[0];
        int n = nums.size();

        while (i < n) {
            if (nums[i] == cur + 1) {
                cur++;
            } else {
                if (start == cur) {
                    ans.push_back(to_string(start));
                } else {
                    ans.push_back(to_string(start) + "->" + to_string(cur));
                }
                start = nums[i];
                cur = start;
            }
            i++;
        }

        if (start == cur) {
            ans.push_back(to_string(start));
        } else {
            ans.push_back(to_string(start) + "->" + to_string(cur));
        }

        return ans;
    }
};
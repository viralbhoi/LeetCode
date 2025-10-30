class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> s;

        int i;
        for (i = 0; i < k; i++) {
            s.insert(nums[i]);
        }

        vector<double> ans;
        auto mid = next(s.begin(), k / 2);

        while (1) {

            if (k % 2 == 1) {
                ans.push_back((double)*mid);
            } else {
                auto pre = prev(mid);
                double temp = ((double)*mid + *pre) / 2;

                ans.push_back(temp);
            }

            if (i == n) {
                break;
            }

            int ins = nums[i];
            int out = nums[i - k];

            s.insert(ins);
            if (ins < *mid) {
                mid--;
            }

            if (out <= *mid) {
                mid++;
            }

            s.erase(s.lower_bound(out));
            i++;
        }

        return ans;
    }
};
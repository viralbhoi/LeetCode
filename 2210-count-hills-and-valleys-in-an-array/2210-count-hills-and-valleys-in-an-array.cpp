class Solution {
public:
    int countHillValley(vector<int>& nums) {
        // step 1 make an array such there is no duplicates

        vector<int> temp;

        for (int it : nums) {
            if (temp.empty()) {
                temp.push_back(it);
            } else if (temp.back() != it) {
                temp.push_back(it);
            }
        }

        int cnt = 0;

        for (int i = 1; i < temp.size() - 1; i++) {
            if ((temp[i] > temp[i - 1] && temp[i] > temp[i + 1]) ||
                (temp[i] < temp[i - 1] && temp[i] < temp[i + 1])) {
                    cnt++;
            }
        }

        return cnt;
    }
};
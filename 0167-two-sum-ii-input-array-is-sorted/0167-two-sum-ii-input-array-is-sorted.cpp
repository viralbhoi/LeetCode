class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        for (int i = 0; i < n - 1; i++) {
            int idx = lower_bound(numbers.begin() + i + 1, numbers.end(),
                                  target - numbers[i]) -
                      numbers.begin();

            if (idx != n && numbers[i] + numbers[idx] == target) {
                return {i + 1, idx + 1};
            }
        }

        return {};
    }
};
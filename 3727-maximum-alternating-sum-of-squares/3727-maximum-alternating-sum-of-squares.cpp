class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        priority_queue<long long> pq;

        for (auto num : nums) {
            pq.push(1ll * num * num);
        }

        int plus = (nums.size() + 1) / 2;

        long long ans = 0;

        for (int i = 0; i < plus; i++) {
            ans += pq.top();
            pq.pop();
        }

        for (int i = 0; !pq.empty();) {
            ans -= pq.top();
            pq.pop();
        }

        return ans;
    }
};
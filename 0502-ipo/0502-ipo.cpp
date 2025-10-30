class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();
        vector<pair<int, int>> costs;

        for (int i = 0; i < profits.size(); i++) {
            costs.push_back({capital[i], profits[i]});
        }

        sort(costs.begin(), costs.end());

        int idx = 0;
        priority_queue<int> maxProfit;

        while (k--) {
            while (idx < n && costs[idx].first <= w) {
                maxProfit.push(costs[idx].second);
                idx++;
            }

            if (maxProfit.empty()) {
                break;
            }

            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};
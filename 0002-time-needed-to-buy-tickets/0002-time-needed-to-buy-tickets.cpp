class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        int t = tickets[k];
        int ans = 0;

        for (int i = 0; i < tickets.size(); i++) {
            if (i <= k)
                ans += min(tickets[i], t);
            else
                ans += min(tickets[i], t - 1);
        }

        return ans;
    }
};
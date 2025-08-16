class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        give(n, {}, k, 1, ans);
        return ans;
    }

private:
    void give(int n, vector<int> ds, int k, int i, vector<vector<int>>& ans) {

        if (ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        for (int j = i; j <= n; j++) {
            ds.push_back(j);
            give(n, ds, k, j+1, ans);
            ds.pop_back();
        }
    }
};
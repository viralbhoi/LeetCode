class Solution {
    int calcHP(int i, int j, vector<vector<int>>& dungeon,
               vector<vector<int>>& dp) {
        if (i == dungeon.size() || j == dungeon[0].size()) {
            return INT_MAX;
        }

        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            return dp[i][j] = max(1, 1 - dungeon[i][j]);
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int bottom = calcHP(i + 1, j, dungeon, dp);
        int right = calcHP(i, j + 1, dungeon, dp);

        return dp[i][j] = max(1, min(bottom, right) - dungeon[i][j]);

    }

public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<vector<int>> dp(n, vector<int> (m,-1));

        return calcHP(0,0,dungeon, dp);
    }
};
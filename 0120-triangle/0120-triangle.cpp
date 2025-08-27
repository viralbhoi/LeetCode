class Solution {
    int rec(vector<vector<int>>& triangle,vector<vector<int>> &dp,int i,int j){
        if(i==triangle.size()){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int bottom = triangle[i][j] + rec(triangle,dp,i+1,j);
        int bottom_right = triangle[i][j] + rec(triangle,dp,i+1,j+1);

        return dp[i][j] = min(bottom, bottom_right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        return rec(triangle,dp,0,0);
    }
};
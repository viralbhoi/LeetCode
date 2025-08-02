class Solution {
    void dfs(int node,vector<int> &vis,vector<vector<int>> &adj){
        vis[node]=1;

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,vis,adj);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>> adj(n+1);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n,0);

        int ans=0;
         
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj);
                ans++;
            }
        }

        return ans;
    }
};
class Solution {
    void dfs(vector<vector<char>>& board,vector<vector<int>>& vis,int row,int col){
        vis[row][col]=1;

        int n = board.size();
        int m = board[0].size();

        int r[] = {0,1,0,-1};
        int c[] = {1,0,-1,0};

        for(int i=0;i<4;i++){
            int nr = row+r[i];
            int nc = col+c[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc] == 'O'){
                dfs(board,vis,nr,nc);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            if(vis[i][0] == 0 && board[i][0] == 'O'){
                dfs(board,vis,i,0);
            }
            if(vis[i][m-1] == 0 && board[i][m-1] == 'O'){
                dfs(board,vis,i,m-1);
            }
        }

        for(int i=0;i<m;i++){
            if(vis[0][i] == 0 && board[0][i] == 'O'){
                dfs(board,vis,0,i);
            }
            if(vis[n-1][i] == 0 && board[n-1][i] == 'O'){
                dfs(board,vis,n-1,i);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
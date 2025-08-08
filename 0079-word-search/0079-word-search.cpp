class Solution {
    bool solve(int i,int j,int idx,vector<vector<char>> &mat, string& word,vector<vector<int>> &vis){
        if(idx == word.size()){
            return true;
        }
        
        int n = mat.size();
        int m = mat[0].size();
    
        
        int dir1[] = {0,1,0,-1};
        int dir2[] = {1,0,-1,0};
        
        if(i<0 || i>=n || j<0 || j>= m || mat[i][j] != word[idx] || vis[i][j]==1){
            return false;
        }
        
        vis[i][j] = 1;
        
        for(int d = 0;d<4;d++){
            int ni = i + dir1[d];
            int nj = j + dir2[d];
            
            if(solve(ni,nj,idx+1,mat,word,vis)){
                return true;
            }
        }
        vis[i][j] = 0;
        
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j] == 0 && board[i][j] == word[0]){
                    if(solve(i,j,0,board,word,vis)){
                        return true;
                    }
                }
            }
        }
        
        return false;

    }
};
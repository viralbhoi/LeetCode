class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        for (int i = 0; i < n; i++) {
            int k = i, j = 0;
            vector<int> temp;
            while (k < n && j < n) {
                temp.push_back(grid[k][j]);
                k++;
                j++;
            }
            sort(temp.begin(), temp.end()); 
            reverse(temp.begin(),temp.end());
            k = i;
            j = 0;
            for (int val : temp) {
                grid[k][j] = val;
                k++;
                j++;
            }
        }

        
        for (int j = 1; j < n; j++) {
            int k = j, i = 0;
            vector<int> temp;
            while (k < n && i < n) {
                temp.push_back(grid[i][k]);
                k++;
                i++;
            }
            sort(temp.begin(), temp.end()); 
            k = j;
            i = 0;
            for (int val : temp) {
                grid[i][k] = val;
                k++;
                i++;
            }
        }

        return grid;
    }
};
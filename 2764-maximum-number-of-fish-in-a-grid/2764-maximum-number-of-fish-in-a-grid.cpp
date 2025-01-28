class Solution {
public:
//dfs approach
    void dfs(vector<vector<int>>&grid , int row, int col , vector<vector<int>>&vis, int& ans){
     int n = grid.size();
     int m =grid[0].size();
     vis[row][col]=1;
     ans+= grid[row][col];
        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        for(int k=0;k<4;k++){
            int nx= row+ dr[k];
            int ny= col + dc[k];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]>0 && !vis[nx][ny]){
                dfs(grid, nx, ny, vis, ans);
            }
        }
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
       for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
              
                if (grid[i][j] > 0 && !vis[i][j]) {
                    int sum = 0; 
                    dfs(grid, i, j, vis, sum); 
                    maxi = max(maxi, sum); 
                }
            }
        }
        
        return maxi;
    }
};
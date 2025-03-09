class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 || j==0 || i==m-1 || j==n-1) && grid[i][j]==1) {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto [dx, dy] : dir){
                int nx = i + dx;
                int ny = j + dy;
                if(nx >= 0 && ny >= 0 && nx < m && ny < n 
                   && !vis[nx][ny] && grid[nx][ny] == 1) {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }

        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};

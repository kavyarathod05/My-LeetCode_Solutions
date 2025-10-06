class Solution {
public:
    bool check(int mid, vector<vector<int>>& grid){
        int n = grid.size();
        if(grid[0][0] > mid) return false;

        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(n,0));

        q.push({0,0});
        vis[0][0] = 1;

        vector<pair<int, int>> dirs= {{0,1}, {1,0}, {-1,0}, {0,-1}};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            if(x == n-1 && y == n-1) return true;

            for(auto [dx, dy] : dirs){
                int nx = x + dx, ny = y + dy;
                if(nx>=0 && ny>=0 && nx<n && ny<n 
                   && !vis[nx][ny] && grid[nx][ny] <= mid){
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxi = max(maxi, grid[i][j]);
            }
        }

        int low = 0, high = maxi, ans = maxi;
        while(low <= high){
            int mid = (low + high) / 2;
            if(check(mid, grid)){
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

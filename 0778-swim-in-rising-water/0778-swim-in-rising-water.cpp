class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<
            pair<int, pair<int,int>>,
            vector<pair<int, pair<int,int>>>,
            greater<>
        > pq;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}}; 

        while(!pq.empty()){
            auto [cost, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            if(x == n-1 && y == n-1) return cost;

            for(auto [dx, dy] : dirs){
                int nx = x + dx, ny = y + dy;
                if(nx>=0 && ny>=0 && nx<n && ny<n){
                    int newCost = max(cost, grid[nx][ny]);
                    if(newCost < dist[nx][ny]){
                        dist[nx][ny] = newCost;
                        pq.push({newCost, {nx, ny}});
                    }
                }
            }
        }
        return -1;
    }
};

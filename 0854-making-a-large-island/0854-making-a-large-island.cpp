class Solution {
public:
    int n;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    int dfs(int i, int j, vector<vector<int>>& grid, unordered_map<int, int>& islandSize, int islandId, vector<vector<int>>& vis) {
        vis[i][j] = islandId;
        int size = 1;

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1 && vis[x][y] == 0) {
                size += dfs(x, y, grid, islandSize, islandId, vis);
            }
        }
        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        unordered_map<int, int> islandSize;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int islandId = 2, maxSize = 0;
        bool hasZero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    int size = dfs(i, j, grid, islandSize, islandId, vis);
                    islandSize[islandId] = size;
                    maxSize = max(maxSize, size);
                    islandId++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    hasZero = true;
                    unordered_set<int> uniqueIslands;

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < n && vis[x][y] > 1) {
                            uniqueIslands.insert(vis[x][y]); 
                        }
                    }

                    int newSize = 1;
                    for (int id : uniqueIslands) {
                        newSize += islandSize[id];
                    }
                    maxSize = max(maxSize, newSize);
                }
            }
        }

        return hasZero ? maxSize : n * n;
    }
};

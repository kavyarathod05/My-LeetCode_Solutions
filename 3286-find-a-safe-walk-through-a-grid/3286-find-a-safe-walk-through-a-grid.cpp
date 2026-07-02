class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool f(int i, int j, vector<vector<int>>& grid, int health,
           vector<vector<bool>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return false;

        if (vis[i][j])
            return false;

        if (grid[i][j] == 1) {
            health--;
            if (health < 1)
                return false;
        }

        if (i == m - 1 && j == n - 1)
            return true;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];

        vis[i][j] = true;

        bool ans = false;
        ans = ans || f(i - 1, j, grid, health, vis);
        ans = ans || f(i + 1, j, grid, health, vis);
        ans = ans || f(i, j - 1, grid, health, vis);
        ans = ans || f(i, j + 1, grid, health, vis);

        vis[i][j] = false;

        return dp[i][j][health] = ans;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {

        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        return f(0, 0, grid, health, vis);
    }
};
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int N = n * m;

        const int MOD = 12345;

        vector<int> pref(N, 1), suff(N, 1);

        // Prefix
        for (int i = 1; i < N; i++) {
            int r = (i - 1) / m;
            int c = (i - 1) % m;
            pref[i] = ( (long long)pref[i - 1] * grid[r][c] ) % MOD;
        }

        // Suffix
        for (int i = N - 2; i >= 0; i--) {
            int r = (i + 1) / m;
            int c = (i + 1) % m;
            suff[i] = ( (long long)suff[i + 1] * grid[r][c] ) % MOD;
        }

        vector<vector<int>> ans(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int idx = i * m + j;
                ans[i][j] = ( (long long)pref[idx] * suff[idx] ) % MOD;
            }
        }

        return ans;
    }
};
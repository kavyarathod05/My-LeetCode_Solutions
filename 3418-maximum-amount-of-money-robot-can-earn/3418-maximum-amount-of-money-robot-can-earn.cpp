class Solution {
public:
    int dp[505][505][3]; 

    int f(int i, int j, vector<vector<int>>& coins, int left) {
        int m = coins.size();
        int n = coins[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return -1e9;

        if (dp[i][j][left] != INT_MIN) 
            return dp[i][j][left];

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] < 0 && left > 0) {
                return dp[i][j][left] = 0; 
            } else {
                return dp[i][j][left] = coins[i][j]; 
            }
        }

        int down = f(i + 1, j, coins, left);
        int right = f(i, j + 1, coins, left);
        int notNeutralized = coins[i][j] + max(down, right);
        
        int neutralized = -1e9; 
        if (coins[i][j] < 0 && left > 0) {
            int down_neu = f(i + 1, j, coins, left - 1);
            int right_neu = f(i, j + 1, coins, left - 1);
            neutralized = 0 + max(down_neu, right_neu);
        }

        return dp[i][j][left] = max(notNeutralized, neutralized);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0] = INT_MIN;
                dp[i][j][1] = INT_MIN;
                dp[i][j][2] = INT_MIN;
            }
        }
        
        return f(0, 0, coins, 2); 
    }
};
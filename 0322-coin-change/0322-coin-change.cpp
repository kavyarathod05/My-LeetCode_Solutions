class Solution {
public:
    int f(int ind, int left, vector<int>& coins, vector<vector<int>>& dp) {
        if (ind == coins.size()) {
            if (left == 0) return 0;
            return 1e9;
        }

        if (dp[ind][left] != -1) return dp[ind][left];

        int notake = f(ind + 1, left, coins, dp);

        int take = 1e9;
        if (coins[ind] <= left) {
            int res = f(ind, left - coins[ind], coins, dp);
            if (res != 1e9) take = 1 + res;
        }

        return dp[ind][left] = min(take, notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(0, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
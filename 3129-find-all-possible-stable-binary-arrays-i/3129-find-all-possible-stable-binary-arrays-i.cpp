class Solution {
public:
    const int MOD = 1e9 + 7;
    int limit;
    
    int solve(int z, int o, int last, vector<vector<vector<int>>>& dp) {
        
        if(z == 0 && o == 0)
            return 1;

        if(dp[z][o][last] != -1)
            return dp[z][o][last];

        long long ans = 0;

        if(last == 1) {  // last block was 1, so place zeros
            for(int k = 1; k <= limit && z >= k; k++) {
                ans = (ans + solve(z - k, o, 0, dp)) % MOD;
            }
        }
        else { // last block was 0, so place ones
            for(int k = 1; k <= limit && o >= k; k++) {
                ans = (ans + solve(z, o - k, 1, dp)) % MOD;
            }
        }

        return dp[z][o][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int lim) {

        limit = lim;

        vector<vector<vector<int>>> dp(
            zero + 1,
            vector<vector<int>>(one + 1, vector<int>(2, -1))
        );

        long long ans = 0;

        // start with zero block
        for(int k = 1; k <= limit && zero >= k; k++)
            ans = (ans + solve(zero - k, one, 0, dp)) % MOD;

        // start with one block
        for(int k = 1; k <= limit && one >= k; k++)
            ans = (ans + solve(zero, one - k, 1, dp)) % MOD;

        return ans;
    }
};

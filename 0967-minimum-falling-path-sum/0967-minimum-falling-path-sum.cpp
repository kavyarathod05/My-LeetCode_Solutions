class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int leftDiag = INT_MAX;
                if(j-1 >= 0) leftDiag = matrix[i][j] + dp[i-1][j-1];
                int rightDiag = INT_MAX;
                if(j+1 < n) rightDiag = matrix[i][j] + dp[i-1][j+1];

                dp[i][j] = min({up, leftDiag, rightDiag});
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};
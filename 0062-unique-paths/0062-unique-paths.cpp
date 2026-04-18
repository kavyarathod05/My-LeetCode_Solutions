class Solution {
public:
    int f(int i, int j, vector<vector<int>>&dp){
        int m = dp.size();
        int n = dp[0].size();
        if(i>=m || j>=n) return 0; 
        if(i==m-1 && j==n-1 ) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int right = f(i,j+1, dp);
        int down = f(i+1, j, dp);
        return dp[i][j]= right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return f(0,0,dp);
    }
};
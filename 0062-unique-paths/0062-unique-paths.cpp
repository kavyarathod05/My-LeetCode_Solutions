class Solution {
public:
    int f(int x, int y,vector<vector<int>>&dp){
        if(x==0 && y==0){
            return 1; 
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        int left=0,right=0;
        if(y>0){

         left= f(x,y-1,dp);
        }
        if(x>0){

         right= f(x-1,y,dp);
        }
        return  dp[x][y]=left+right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m-1,n-1,dp);
    }
};
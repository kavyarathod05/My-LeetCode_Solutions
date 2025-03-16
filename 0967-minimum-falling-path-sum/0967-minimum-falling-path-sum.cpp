class Solution{
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
         vector<vector<int>> dp(n,vector<int>(n,INT_MIN));
        for(int i=0;i<n;i++){
            ans=min(ans,f(matrix,0,i,n,dp));
        }
        return ans;
    }
private:
    int f(vector<vector<int>>& matrix,int i,int j,int n,vector<vector<int>>&dp){
        if(j<0) return INT_MAX;
        if(i>=n || j>=n) return INT_MAX;
        if(i==n-1) return matrix[i][j];
        if(dp[i][j]!=INT_MIN) return dp[i][j];
        int a=f(matrix,i+1,j-1,n,dp);
        int b=f(matrix,i+1,j,n,dp);
        int c=f(matrix,i+1,j+1,n,dp);
        return dp[i][j]= min(a,min(b,c))+matrix[i][j];
    }
};
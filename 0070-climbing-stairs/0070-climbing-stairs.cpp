class Solution
{
    public:
        int climbStairs(int n) {
            if(n<=2){
                return n;
            }
            vector<int>dp(n+1,-1);
            dp[2]=2;
            dp[3]=3;
            for(int i=4;i<=n;i++){
                dp[i]=dp[i-1]+dp[i-2];
            }
            return dp[n];
        }
};
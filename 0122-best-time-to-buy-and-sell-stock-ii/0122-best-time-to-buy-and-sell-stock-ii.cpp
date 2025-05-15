class Solution {
public:
    int f(vector<int>&prices, int ind, int buy, vector<vector<int>>&dp){
        int n = prices.size();
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int ans=0;
        if(buy==0){
            ans= max(0+f(prices, ind+1,buy, dp), -prices[ind]+f(prices,ind+1,!buy, dp));
        }
        if(buy==1){
            ans= max(0+f(prices, ind+1,buy, dp), +prices[ind]+f(prices,ind+1,!buy, dp));
        }

        return dp[ind][buy]= ans;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans= f(prices, 0, 0, dp);
        return ans;
    }
};
class Solution {
public:
    int f(int ind, int buy , int cap ,vector<int>& prices, vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(ind==n || cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy){
            // then 2 options either i buy or not buy
            return dp[ind][buy][cap]= max(-prices[ind]+f(ind+1,0,cap,prices ,dp),f(ind+1, buy, cap, prices,dp));
        }
        else{
            return dp[ind][buy][cap]=  max(prices[ind]+f(ind+1, 1, cap-1,prices,dp), f(ind+1, buy, cap, prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        // ind , buy/sell ,cap profit i want to maximise;
        int n = prices.size();
        // for second one buy ==1 then you can buy
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return f(0,1,2, prices,dp);
    }
};
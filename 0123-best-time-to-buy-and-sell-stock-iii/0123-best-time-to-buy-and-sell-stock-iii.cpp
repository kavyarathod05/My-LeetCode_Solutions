class Solution {
public:
    int f(int ind, int buy , int cap , vector<int>&prices, vector<vector<vector<int>>>&dp){
        int n  = prices.size();
        if(ind==n || cap==0) return 0;
        if(dp[ind][buy][cap] != -1){
            return dp[ind][buy][cap];
        }
        int profit;
      if (buy == 0) { 
        profit = max(0 + f( ind + 1, 0, cap,prices, dp),
                     -prices[ind] + f( ind + 1, 1, cap,prices, dp));
    }

    if (buy == 1) { 
        profit = max(0 + f( ind + 1, 1, cap,prices, dp),
                     prices[ind] + f( ind + 1, 0, cap - 1,prices, dp));
    }

    
    return dp[ind][buy][cap] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0,0,2,prices,dp);

    }
};
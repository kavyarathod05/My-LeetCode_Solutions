class Solution {
public:
    int f(int ind, int last , vector<int>&nums, vector<int>&dp){
        int n =nums.size();
        if(ind<0 ) return 0;
        if(dp[ind]!= -1) return dp[ind];
        int take = INT_MIN;
       take  = f(ind-2, ind, nums,dp)+nums[ind];
        
        int nottake= f(ind-1, last, nums,dp);        
        return dp[ind]= max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return f(n-1,-1,nums,dp);   
    }
};
class Solution {
public:
    int f(vector<int>&nums, int ind,vector<int>&dp){
       int n = nums.size();
       if(ind<0) return 0;
       if(ind==0) return nums[0];
       int pick = INT_MIN;
       if(dp[ind]!=-1) return dp[ind];
     
       pick = nums[ind]+f(nums,ind-2,dp);
       
      int notpick = 0+ f(nums,ind-1,dp);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return f(nums,n-1,dp);
    }
};
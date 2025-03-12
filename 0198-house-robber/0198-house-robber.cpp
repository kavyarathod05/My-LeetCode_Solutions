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
        if (n == 1) return nums[0]; 
        dp[0]=nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2;i<n;i++){
            int pick= INT_MIN;
            if(i>1){
             pick= nums[i]+dp[i-2];
            }
            int nonpick= 0+dp[i-1];
            dp[i]= max(pick,nonpick);

        }
        return dp[n-1];
    }
};
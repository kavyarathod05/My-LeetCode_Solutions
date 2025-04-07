class Solution {
public:
    bool f(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return dp[ind][target]= true;
        if(ind==0 ) return (nums[ind]==target)?(dp[ind][target]=true):(dp[ind][target]=false);
        if(dp[ind][target] != -1) return dp[ind][target];
        bool notake = f(ind-1, target, nums,dp);
        bool take = false;
        if(target>nums[ind]){
            take = f(ind-1, target- nums[ind],nums,dp);
        }
        return dp[ind][target]= (take||notake); 
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 != 0 )return false;
        int target= sum/2;
        vector<vector<int>>dp(n+1, vector<int>(target+1,-1));
        return f(n-1, target, nums,dp);
    }
};
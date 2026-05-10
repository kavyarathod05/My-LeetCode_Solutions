class Solution {
public:
    int solve(int ind, vector<int>&nums, int target, vector<int>&dp){
        int n = nums.size();
        if(ind == n-1){
            return 0;
        }

        if(dp[ind]!= -2) return dp[ind];

        int ans=  -1;
        for(int j=ind+1; j<n;j++){
            if(abs(nums[ind]-nums[j]) <= target){
                int temp = solve(j , nums, target , dp);

                if(temp!= -1){
                    ans =max(ans, 1+temp);
                } 
            }
        }
        return dp[ind]= ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n,-2);

        return solve(0, nums, target, dp);
    }
};
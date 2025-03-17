class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int sum = 0;
        
        for (int num : nums) {
            sum += num;
        }

        if (sum % 2 == 1) return false;

        int target = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        if (nums[0] <= target) dp[0][nums[0]] = true;

        
        for (int ind = 1; ind < n; ind++) {
            for (int t = 0; t <= target; t++) {
                bool notTake = dp[ind - 1][t]; 
                bool take = false;
                if (t >= nums[ind]) {
                    take = dp[ind - 1][t - nums[ind]]; 
                }
                dp[ind][t] = take || notTake;
            }
        }

        return dp[n - 1][target];
    }
};

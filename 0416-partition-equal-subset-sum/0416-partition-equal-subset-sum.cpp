class Solution {
public:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (ind == 0) return nums[0] == target;

        if (dp[ind][target] != -1) return dp[ind][target];

        bool take = false;
        if (target >= nums[ind]) {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }

        bool nottake = f(ind - 1, target, nums, dp);

        return dp[ind][target] = (take || nottake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};

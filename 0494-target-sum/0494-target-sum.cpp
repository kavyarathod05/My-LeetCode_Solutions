class Solution {
public:
    int f(int ind, vector<int>& nums, int t) {
        if (ind < 0) {
            return t == 0 ? 1 : 0;
        }

        int add = f(ind - 1, nums, t - nums[ind]);
        int sub = f(ind - 1, nums, t + nums[ind]);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return f(n - 1, nums, target);
    }
};

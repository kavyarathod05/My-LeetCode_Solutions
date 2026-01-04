class Solution {
public:
    void f(int ind, vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int k, int n) {
        if (temp.size() == k) {
            if (n == 0)
                ans.push_back(temp);
            return;
        }
        if (ind >= nums.size()) return;

        f(ind + 1, nums, ans, temp, k, n);

        if (nums[ind] <= n) {
            temp.push_back(nums[ind]);
            f(ind + 1, nums, ans, temp, k, n - nums[ind]);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        for (int i = 1; i <= 9; i++) nums.push_back(i);
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, nums, ans, temp, k, n);
        return ans;
    }
};

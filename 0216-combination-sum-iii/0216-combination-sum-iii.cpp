class Solution {
public:
    void solve(int k, int n, vector<int>& nums, vector<int>& temp,
               vector<vector<int>>& ans, int ind) {
        if (k < 0 || n < 0) {
            return;
        }
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
        for (int i = ind; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            solve(k - 1, n - nums[i], nums, temp, ans, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums(9);
        vector<int> temp;
        for (int i = 0; i < 9; i++) {
            nums[i] = i + 1;
        }
        vector<vector<int>> ans;
        solve(k, n, nums, temp, ans, 0);
        return ans;
    }
};
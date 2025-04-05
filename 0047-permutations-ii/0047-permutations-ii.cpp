class Solution {
public:
    void recurse(int ind, vector<int>& nums, vector<vector<int>>& ans) {
        if (ind == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {
            swap(nums[i], nums[ind]);
            recurse(ind + 1, nums, ans);
            swap(nums[i], nums[ind]); 
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> allPermutations;
        recurse(0, nums, allPermutations);
        set<vector<int>> uniquePerms(allPermutations.begin(), allPermutations.end());
        vector<vector<int>> ans(uniquePerms.begin(), uniquePerms.end());
        return ans;
    }
};

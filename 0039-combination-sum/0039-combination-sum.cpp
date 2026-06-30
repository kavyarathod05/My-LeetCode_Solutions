class Solution {
public:
    void f(int ind, vector<int> temp, vector<vector<int>>& ans,
           vector<int>& cand, int target) {
        int n = cand.size();
        if (ind == n) {
            if (target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        f(ind + 1, temp, ans, cand, target);
        if (cand[ind] <= target) {
            temp.push_back(cand[ind]);
            f(ind, temp, ans, cand, target - cand[ind]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> temp;
        f(0, temp, ans, candidates, target);
        return ans;
    }
};
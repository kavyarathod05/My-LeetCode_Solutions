class Solution {
public:
    void f(int ind, vector<int>&nums, int k,vector<int>&temp ,vector<vector<int>>&ans){
        if(k==0){
            ans.push_back(temp);
            return;
        }
        if(ind>= nums.size()){
            return ;
        }
        if(nums[ind]<=k){
            temp.push_back(nums[ind]);
            f(ind,nums,k-nums[ind],temp,ans);
            temp.pop_back();
        }
     f(ind+1, nums,k,temp,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
         f(0,candidates, target,temp,ans);
        return ans;
    }
};
class Solution {
public:
    void solve( vector<int>&nums, vector<int>& temp, vector<vector<int>>&ans,int ind){
        int n = nums.size();
        if(ind==n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums, temp ,ans , ind+1);// take part
        temp.pop_back(); // remove last element as to perform take/not take
        solve(nums,temp ,ans, ind+1); //Not take part

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>>ans;
        solve(nums,temp ,ans, 0);
        return ans;
    }
};
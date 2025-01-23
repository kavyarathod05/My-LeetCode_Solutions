class Solution {
public:
    void solve(vector<int>&c, int t, vector<vector<int>>&ans, vector<int>&temp, int ind){
        if(ind==c.size() || t<0){
            return;
        }
        if(t==0 ){
            ans.push_back(temp);
            return;
        }
        //take
        temp.push_back(c[ind]);
        solve(c, t-c[ind], ans, temp , ind);
        //not take
        temp.pop_back();
        solve(c, t, ans, temp , ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n = c.size();
        vector<vector<int>> ans;
        vector<int> temp;
        solve(c, target, ans, temp,0);
        return ans;
    }
};
class Solution {
public:
    int solve(int i,int k,int t,vector<vector<int>>&q,vector<vector<int>>&dp){
        if(t==0)return k;
        if(t<0 || k>=q.size())return 1e9;
        if(dp[t][k]!=-1)return dp[t][k];
        int ntake=solve(i,k+1,t,q,dp);
        int take=1e9;
        if(i>=q[k][0] && i<=q[k][1]){
           take= solve(i,k+1,t-q[k][2],q,dp);
        }
        return dp[t][k]=min(take,ntake);
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            vector<vector<int>>dp(nums[i]+1,vector<int>(q.size()+1,-1));
            ans=max(ans,solve(i,0,nums[i],q,dp));
        }
       
        return (ans>q.size())?-1:ans;
    }
};
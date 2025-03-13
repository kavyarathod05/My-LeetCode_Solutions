class Solution {
public:
    bool transform(vector<int>&nums, vector<vector<int>>&queries, int mid){
        int n = nums.size();
        int sum=0;
        vector<int>diff(n+1,0);
        for(int i=0;i<mid;i++){
            auto it= queries[i];
            diff[it[0]]+= it[2];
            
            diff[it[1]+1]-=it[2];
        }
        for(int i=0;i<n;i++){
            sum+=diff[i];
            if(sum<nums[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(),left=0,right=queries.size(),ans=-1;
        if(!transform(nums,queries,right)) return -1;
        while(left<=right){
            int mid= (left+right)/2;
            if(transform(nums,queries,mid)){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};
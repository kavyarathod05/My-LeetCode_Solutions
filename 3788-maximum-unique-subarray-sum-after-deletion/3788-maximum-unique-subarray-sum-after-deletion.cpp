class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());
        if(maxi<0){
            return maxi;
        }
        set<int>mp ;
        for(auto it:nums){
            mp.insert(it);
        }
        int sum=0;
        for(auto it:mp){
            if(it>0){

            sum+=it;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n = nums.size();
        int curr=-1;
        int ans=0;
        for(int i=0;i<n;i++){
            if(curr==-1) {
                curr=nums[i];
                ans++;
            }
            else if(curr <= nums[i]){
                curr=nums[i];
                ans++;
            }
        }

        return ans;
    }
};
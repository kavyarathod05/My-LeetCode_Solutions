class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum=0;
        int currentSum =nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                currentSum+=nums[i];
            }
            else{
                maxSum= max(maxSum, currentSum);
                currentSum= nums[i];
            }
        }
        return max(maxSum, currentSum);
    }
};
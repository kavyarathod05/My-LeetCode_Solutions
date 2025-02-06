class Solution {
public:
    int atmost(vector<int>&nums, int goal){
        int left=0;
        if(goal<0) return 0;
        int n = nums.size();
        int right=0;
        int sum =0;
        int cnt =0;
        while(right<n){
            sum+=nums[right];
            while(sum>goal){
            sum-=nums[left];
            left++;
            }
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return atmost(nums, goal)- atmost(nums, goal-1);
    }
};
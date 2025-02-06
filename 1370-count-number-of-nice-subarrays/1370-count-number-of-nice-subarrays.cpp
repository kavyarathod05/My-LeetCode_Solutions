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
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        return atmost(nums,k)- atmost(nums, k-1);
    }
};
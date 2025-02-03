class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi =0;
        int inc=1;
        int dec=1;
        if(n==1) return 1;
        for (int i = 1; i < n; i++) {
            if(nums[i]>nums[i-1]) inc++ ,dec=1;
            else if(nums[i]<nums[i-1]) dec++, inc=1;
            else inc=dec=1;
            maxi =max({maxi,inc, dec});
        }
        return maxi;
        
    }
};

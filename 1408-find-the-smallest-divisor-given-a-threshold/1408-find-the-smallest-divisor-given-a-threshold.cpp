class Solution {
public:
     
    int smallestDivisor(vector<int>& nums, int thresh) {
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=low+(high-low)/2;
            int c=0;
            for(auto x:nums)c+=(((x-1)/mid)+1);
             if(c<=thresh){
                 high=mid-1;
             }
             else low=mid+1;
        }
        return low;
    }
};
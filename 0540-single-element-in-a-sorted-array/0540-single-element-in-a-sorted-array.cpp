class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int ans= -1;

        int low =0 ,high = n-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid%2==1) mid--;
            if( mid < n-1 && nums[mid]== nums[mid+1]){
                low = mid+2;
            }
            else{
                ans = nums[mid];
                high = mid-2;
            }
        }
        return ans;
    }
};
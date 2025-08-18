class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0 ,high= n-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[low]<=nums[mid]){
                if(target<=nums[mid] && nums[low]<=target){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else if(nums[mid] <= nums[high] ){
                if(target<=nums[high] && nums[mid]<=target){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }

        }
        return -1;
    }
};
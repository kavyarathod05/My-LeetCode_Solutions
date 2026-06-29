class Solution {
public:
// mid == mid+1 so that left side is safe move to right side
// if not safe then move left 
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high= n-1;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            if(mid%2==1) mid--;
            if(mid<n-1 && nums[mid] == nums[mid+1]) {
                low = mid+2;
                // so element is on right
            }
            else{
                ans = mid;
                high = mid-2;
            }
        }
        return nums[ans];
    }
};
//  [1,1,2,3,3,4,4,8,8] 
// low = 0 , high = 8 , mid = 4 so check if prev not equal also if prev equal then move left back 
// 
class Solution {
public:
    int checkPairs(vector<int>&nums, int mid){
        int total=0;
        int n = nums.size();
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1]) <=mid){
                total++;
                i++;
            }
        }

        return total;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int low= 0;
        int high = nums[n-1];
        while(low<=high){
            int mid = low + (high-low)/2;
            int total = checkPairs(nums , mid);
            if(total >= p ){
                high= mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return low;
    }
};
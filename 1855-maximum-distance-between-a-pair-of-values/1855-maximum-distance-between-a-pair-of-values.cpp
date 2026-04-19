class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int maxi = 0 ;
        for(int i=0;i<n;i++){
            int val = nums1[i];
            int low = i;
            int high = m-1;
            int ans= -1;
            while(low<=high){
                int mid = (low+high)/2; 
                if(nums2[mid]>=val){
                    ans= mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            if(ans==-1) continue;
            maxi = max(maxi , ans-i);
        }
        return maxi;
    }
};
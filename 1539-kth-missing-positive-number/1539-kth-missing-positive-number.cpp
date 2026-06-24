class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int low = 0;
        int high = n-1;
        int ans = -1;
        int m = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int missing = arr[mid]-mid-1;
            if(missing < k){
                ans = mid;
                m = k-missing;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(ans==-1) return k;
        return arr[ans] + m;
    }
};
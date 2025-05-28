class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int front=1;
        int ans= INT_MIN;
        for(int i=0;i<n;i++){
            if(front==0) front=1;
            front*= nums[i];
            ans= max(ans, front);
        }
        front=1;
        for(int i=n-1;i>=0;i--){
            if(front==0) front=1;
            front*= nums[i];
            ans= max(ans, front);
        }
        return ans;
    }
};
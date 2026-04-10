class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n= nums.size();
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(i!=j && j!=k && i!=k){
                        if(nums[i]==nums[j] && nums[j]==nums[k]){
                            mini = min(mini , abs(i-j)+abs(j-k)+abs(k-i));
                        }
                    }
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n  = nums.size();
        int i=0,j=0;
        int ans = 0;
        while(j<n){
            while(k<=0 && i<=j && nums[j]==0){
                if(nums[i]==0){
                    k++;
                }
                i++;
                cout<<"j"<<j <<" i"<<i<<" k"<<k<<endl;
            }
            if(nums[j]==0 && k>0){
                k--;
            }
            ans = max(ans,  j-i+1);
            j++;
        }
        return ans;
    }
};
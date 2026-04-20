class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        int curr = nums[0];
        int cnt= 1;
        for(int i=1;i<n;i++){
            if(nums[i]==curr) cnt++;
            else{
                cnt--;
                if(cnt==0){
                    curr = nums[i];;
                    cnt=1;
                }
            }
            maxi = max(maxi , cnt);
        }
        return curr;
    }
};
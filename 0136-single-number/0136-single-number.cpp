class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt=0;
        int n = nums.size();
        for(auto it:nums){
            cnt ^= it;
        }
        return cnt;
    }
};
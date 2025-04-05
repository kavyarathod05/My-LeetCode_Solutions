class Solution {
public:
const int MOD = 1e9 + 7;
     int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp /= 2;
        }
        return static_cast<int>(result);
    }

    int numberOfGoodPartitions(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            if(mp.find(nums[i])==mp.end()){
            mp[nums[i]]=i;
            }
        }
        int smallest= 0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr= max(curr, mp[nums[i]]);
            if(curr==i){
                smallest++;
            }
           
        }
        return smallest > 0 ? modPow(2, smallest - 1, MOD) : 0;
    }
};
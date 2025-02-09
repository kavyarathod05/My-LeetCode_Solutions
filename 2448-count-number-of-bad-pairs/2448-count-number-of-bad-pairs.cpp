class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long ans =0;
        unordered_map<int , int> mp;
        for(int i=0;i<n;i++){
            ans += mp[nums[i]-i];
            mp[nums[i]-i]++;
        }
        return (n * (n - 1)) / 2 - ans;

    }
};
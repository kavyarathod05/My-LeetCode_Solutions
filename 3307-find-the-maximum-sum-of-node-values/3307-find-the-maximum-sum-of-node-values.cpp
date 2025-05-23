class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long cnt=0;
        long long sum=0;
        long long bali=INT_MAX;

        for(auto it:nums){
            if((it^k)>it){
                cnt++;
                bali = min(bali, (long long)((it^k) -it));
                sum+=it^k;
            }
            else{
                sum+=it;
                bali= min(bali, (long long)(it-(it^k)));
            }
        }

        if(cnt%2==0) return sum;
        return sum-bali;
    }
};
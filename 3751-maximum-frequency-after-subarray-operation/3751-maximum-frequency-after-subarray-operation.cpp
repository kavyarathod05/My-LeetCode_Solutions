class Solution {
public:
    int countMaxGain(vector<int>&nums, int value, int k){
        int maxGain =0;
        int currGain=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==k) currGain--;
            if(nums[i]==value) currGain++;
            if(currGain<0) currGain=0;
            maxGain= max(maxGain, currGain);
        }
        return maxGain;
    }
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;;
        for(auto num : nums){
            freq[num]++;
        }
        int maxfreq=0;
        for(auto& [value,_]: freq){
            maxfreq= max(maxfreq, countMaxGain(nums, value, k));
        }
        return maxfreq+ freq[k];
    }
};

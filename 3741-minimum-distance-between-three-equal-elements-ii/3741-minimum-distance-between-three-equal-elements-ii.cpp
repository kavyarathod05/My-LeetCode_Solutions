class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int  n =nums.size();
        unordered_map<int,int> last, freq;
        vector<int> track(n,0);
        for(int i=0;i<n;i++){
            if(track[i]==0 ){
                if(last.find(nums[i])==last.end()){
                    last[nums[i]]= i;
                    track[i]= i;
                }
                else{
                    track[i] = last[nums[i]];
                    last[nums[i]]=i;
                }
                freq[nums[i]]++;
            }
        }
        int mini = INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            if(freq[nums[i]]>=3 && track[i] != track[track[i]]){
                mini = min(mini , i - track[track[i]]);
            }
        }
        if(mini ==INT_MAX) return -1;
        return 2*mini;
    }
};
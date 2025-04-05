class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int  n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long sum= (long long)target-(long long) nums[i] -(long long)nums[j];
                int c= j+1;
                int d=n-1;
                while(c<d){
                    if(nums[c]+nums[d]<sum){
                        c++;
                    }
                    else if(nums[c]+nums[d]>sum){
                        d--;
                    }
                    else{
                       ans.push_back({nums[i],nums[j],nums[c],nums[d]});
                       int temp1=c;
                       int temp2=d;
                       while(c<d && nums[c]==nums[temp1])c++;
                       while(c<d && nums[d]==nums[temp2])d--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;
                while(i+1<n && nums[i]==nums[i+1]) i++;
            }
        }
        
        return ans;
    }
};
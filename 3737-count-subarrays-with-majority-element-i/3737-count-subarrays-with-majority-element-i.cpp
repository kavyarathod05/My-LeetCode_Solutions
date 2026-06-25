class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;

        vector<int> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + (nums[i] == target ? 1 : -1);
        }

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int sum = prefix[j + 1] - prefix[i];
                if(sum > 0) cnt++;
            }
        }

        return cnt;
    }
};

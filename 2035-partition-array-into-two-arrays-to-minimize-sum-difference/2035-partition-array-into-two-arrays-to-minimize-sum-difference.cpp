class Solution {
public:
    int find(int val, vector<int>& nums){
        // Lower Bound Binary Search
        int l=0;
        int r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==val) return val;
            if(nums[mid]>val) r=mid-1;
            else l=mid+1;
        }

        if (r < 0) return nums[0];
        if (l >= nums.size()) return nums[nums.size() - 1];

        return (abs(nums[l] - val) < abs(nums[r] - val)) ? nums[l] : nums[r];
    }

    void findSum(int ind, int n, int cnt, int sum, vector<int>& nums, vector<vector<int>>& subset){
        if(ind>=n){
            subset[cnt].push_back(sum);
            return;
        }

        findSum(ind+1, n, cnt, sum, nums, subset);
        findSum(ind+1, n, cnt+1, sum+nums[ind], nums, subset);
    }

    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum / 2;

        // Step1: Divide the array in 2 halvess and find all the subset sums
        vector<vector<int>> subset1(n/2+1), subset2(n/2+1);
        findSum(0, n/2, 0, 0, nums, subset1);
        findSum(n/2, n, 0, 0, nums, subset2);

        // Step 2: Sort the second halve subset
        for(int i = 0; i <= n / 2; i++) {
            sort(subset2[i].begin(), subset2[i].end());
        }

        // Step 3: Perform binary search on the second halve for every subset sum
        int res=INT_MAX;
        for(int i=0;i<=n/2;i++){
            for (int sum1 : subset1[i]) {
                int targetVal = target - sum1;
                int val = find(targetVal, subset2[n / 2 - i]);

                res = min(res, abs(totalSum - 2 * (sum1 + val)));
            }
        }

        return res;
    }
};
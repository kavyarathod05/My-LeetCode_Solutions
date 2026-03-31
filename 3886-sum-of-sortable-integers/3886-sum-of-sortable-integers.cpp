class Solution {
public:
    bool isValid(vector<int>& nums, int k) {
        int n = nums.size();
        int mini = 0;

        for (int i = 0; i < n; i += k) {
            if (nums[i] < mini) return false;

            int maxi = nums[i];
            bool point = false;

            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] < mini) return false;

                if (nums[j - 1] > nums[j]) {
                    if (point) return false;
                    point = true;
                }

                maxi = max(maxi, nums[j]);
            }

            if (point) {
                if (nums[i] < nums[i + k - 1]) return false;
            }

            mini = maxi;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (isValid(nums, i)) ans += i;
            }
        }

        return ans;
    }
};
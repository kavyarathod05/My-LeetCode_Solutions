class Solution {
public:
    int nextGreaterElement(int n) {
        int original = n; 
        vector<int> nums;

        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());

        int m = nums.size();
        int i = m - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i < 0) return -1; 

        for (int j = m - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                swap(nums[j], nums[i]);
                break;
            }
        }

        reverse(nums.begin() + i + 1, nums.end());

        long long val = 0;
        for (int digit : nums) {
            val = val * 10 + digit;
            if (val > INT_MAX) return -1;
        }

        return (val > original) ? (int)val : -1;
    }
};
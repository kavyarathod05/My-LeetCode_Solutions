class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> nums;

        while (n > 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        reverse(nums.begin(), nums.end());

        if (!next_permutation(nums.begin(), nums.end()))
            return -1;

        long long val = 0;
        for (int digit : nums) {
            val = val * 10 + digit;
            if (val > INT_MAX) return -1;
        }

        return (int)val;
    }
};
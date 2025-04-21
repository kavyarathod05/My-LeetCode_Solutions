class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int n = differences.size();
        long long prefix = 0;
        long long minVal = 0, maxVal = 0;

        for (int diff : differences) {
            prefix += diff;
            minVal = min(minVal, prefix);
            maxVal = max(maxVal, prefix);
        }

        long long validLower = lower - minVal;
        long long validUpper = upper - maxVal;

        long long count = validUpper - validLower + 1;
        return count > 0 ? count : 0;
    }
};

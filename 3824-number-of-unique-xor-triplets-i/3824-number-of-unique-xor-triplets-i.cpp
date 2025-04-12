class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
    
      int n = nums.size();
    if (n < 3)
        return n;
    else
        return std::pow(2, static_cast<int>(std::log2(n)) + 1);
    }
};
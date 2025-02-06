class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hm;
        hm.reserve(n * (n - 1) / 2); 
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int mul = nums[i] * nums[j];
                hm[mul]++;
            }
        }
        
        int total = 0;
        for (const auto &it: hm) {
            int count = it.second;
            if (count >= 2)
                total += count * (count - 1) / 2; 
        }
        
        return total * 8;  
    }
};
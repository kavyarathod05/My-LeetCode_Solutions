class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        int n = capacity.size();
        long long ans = 0;
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + capacity[i];
        }

       
        unordered_map<int, unordered_map<long long, int>> mp;
        
        for (int r = 2; r < n; r++) {
            
            int l = r - 2;
            mp[capacity[l]][prefix[l + 1]]++;
            
            long long target_val = prefix[r] - capacity[r];
            
      
            if (mp.find(capacity[r]) != mp.end() && mp[capacity[r]].find(target_val) != mp[capacity[r]].end()) {
                ans += mp[capacity[r]][target_val];
            }
        }
        
        return ans;
    }
};
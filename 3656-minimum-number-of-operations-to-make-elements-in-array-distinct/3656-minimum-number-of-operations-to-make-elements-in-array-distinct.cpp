class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp; 
        
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int start = 0;
        int op = 0;

        while (true) {
            bool alldis = true;
            for (auto& [key, fre] : mp) {
                if (fre > 1) {
                    alldis = false;
                    break;
                }
            }
            if (alldis) break;

            for (int i = 0; i < 3 && start < n; i++) {
                int num = nums[start]; 
                mp[num]--;
                if (mp[num] == 0) {
                    mp.erase(num);
                }
                start++;
            }

            op++; 
        }

        return op;
    }
};

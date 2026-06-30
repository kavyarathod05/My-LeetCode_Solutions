class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt = 0;
        unordered_map<char, int> mp;

        int l = 0, r = 0;

        while (r < n) {
            mp[s[r]]++;
            // shrinking phase
            while (mp['a'] > 0 && mp['b'] > 0 && mp['c'] > 0) {
                cnt += (n - r);
                mp[s[l]]--;
                l++;
            }
            // expansion
            r++;
        }

        return cnt;
    }
};
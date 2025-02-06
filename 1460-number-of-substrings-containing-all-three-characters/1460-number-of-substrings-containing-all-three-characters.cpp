class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        int left=0, right=0;
        int cnt =0;
        while(right<n){
            mp[s[right]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                cnt += 1 + (n-right-1);
                mp[s[left]] -= 1;
                 left++;
            }
            right++;
        }
        return cnt;
    }
};
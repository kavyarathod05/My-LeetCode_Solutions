class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> dp(26, vector<int>(26, 0));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string c = words[i];
            if (dp[c[1] - 'a'][c[0] - 'a'] > 0) {
                ans += 4;
                dp[c[1] - 'a'][c[0] - 'a']--;
            } else {
                dp[c[0] - 'a'][c[1] - 'a']++;
            }
        }

        bool mid = false;
        for (int i = 0; i < 26; i++) {
            if (dp[i][i] > 0) {
                mid = true;
                break;
            }
        }

        if (mid) ans += 2;
        return ans;
    }
};

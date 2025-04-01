class Solution {
public:
    static bool comp(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }

    bool check(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1) return false;
        int first = 0, second = 0;
        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                second++;
            }
            first++;
        }
        return second == s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        if (n == 0) return 0;

        sort(words.begin(), words.end(), comp);
        vector<int> dp(n, 1);
        int maxSize = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[i], words[j]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    maxSize = max(maxSize, dp[i]);
                }
            }
        }
        return maxSize;
    }
};

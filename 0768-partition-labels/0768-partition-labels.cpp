class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> ans;
        unordered_map<char, int> last;
        for (int i = 0; i < n; i++) {
            last[s[i]] = i;
        }
        int i = 0;
        while (i < n) {
            int end = last[s[i]];
            int j = i;
            while (j <= end) {
                end = max(end, last[s[j]]);
                j++;
            }
            ans.push_back(j - i);
            i = j;
        }

        return ans;
    }
};

class Solution {
public:
    int maxSubstrings(string word) {
        vector<vector<int>> mpp(26);
        int n = word.size(); 
        for (int i = 0; i < n; i++)
            mpp[word[i] - 'a'].push_back(i);

        vector<pair<int, int>> pairs;
        for (int i = 0; i < 26; i++) {
            vector<int>& p = mpp[i];
            for (int j = 0; j < p.size(); j++) {
                int target = p[j] + 3;
                auto it = lower_bound(p.begin() + j + 1, p.end(), target);
                if (it != p.end()) {
                    pairs.push_back({p[j], *it});
                }
            }
        }

        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int cnt = 0, last = -1;
        for (auto &p : pairs) {
            if (p.first > last) {
                cnt++;
                last = p.second;
            }
        }

        return cnt;
    }
};

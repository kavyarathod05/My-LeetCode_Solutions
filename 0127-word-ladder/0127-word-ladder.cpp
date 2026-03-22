class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (auto& words : wordList) {
            st.insert(words);
        }
        queue<pair<string,int>>q;
        st.erase(beginWord);
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            string s = it.first;
            int dist = it.second;
            if(endWord==s) return dist;
            for (int i = 0; i < s.size(); i++) {
                char ch = s[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    s[i]=c;
                    if(st.count(s)){
                        q.push({s,dist+1});
                        st.erase(s);
                    }
                }
                s[i] = ch;
            }
        }
        return 0;
    }
};
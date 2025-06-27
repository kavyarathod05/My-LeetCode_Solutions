class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n  =wordList.size();
        queue<pair<string, int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        while(!q.empty()){
            string s= q.front().first;
            int dis= q.front().second;
            q.pop();
            if(s==endWord){
                return dis;
            }
            for(int i=0;i<s.size();i++){
                char  c= s[i];
                for(char ch='a'; ch<='z';ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        st.erase(s);
                        q.push({s,dis+1});
                    }
                }
                s[i]=c;
            }
        }
        return 0;
    }
};
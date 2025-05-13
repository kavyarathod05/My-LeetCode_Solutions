class Solution {
public:
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;

    void dfs(string word, vector<string>& seq){
        if(word == b){
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }
        int steps = mpp[word];
        for(int i = 0; i < word.size(); i++){
            char ori = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++){
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = ori;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};

        queue<string> q;
        b = beginWord;
        mpp[beginWord] = 0;
        q.push(beginWord);

        while(!q.empty()){
            string top = q.front();
            int steps = mpp[top];
            q.pop();

            for(int i = 0; i < top.size(); i++){
                char ori = top[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    top[i] = ch;
                    if(st.find(top) != st.end()){
                        if(mpp.find(top) == mpp.end()){
                            mpp[top] = steps + 1;
                            q.push(top);
                        }
                    }
                }
                top[i] = ori;
            }
        }

        if(mpp.find(endWord) != mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};

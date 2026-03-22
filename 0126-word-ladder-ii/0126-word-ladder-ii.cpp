class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<string>> ans;
    string b;
    void dfs(string end, vector<string>&temp){
        int steps = mp[end];
        if(end==b){
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            reverse(temp.begin(), temp.end());
            cout<<"done"<<endl;
            return;
        }
        for(int i=0;i<end.size();i++){
            char ch = end[i];
            for(char c ='a'; c<='z';c++){
                end[i]=c;
                if(mp.find(end)!=mp.end() && mp[end]+1 == steps){
                    temp.push_back(end);
                    dfs(end, temp);
                    temp.pop_back();
                }
            }
            end[i]=ch;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        b= beginWord;
        st.erase(beginWord);
        int depth = 1;
        mp[beginWord]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string s = it.first;
            int len  = it.second;
            if(s==endWord){
                depth = len;
                break;
            }
            for(int i=0;i<s.size();i++){
                char c = s[i];
                for(char ch = 'a' ; ch<='z' ; ch++){
                    s[i]=ch;
                    if(st.find(s)!=st.end()){
                        if(mp.find(s)==mp.end()){
                        q.push({s, len+1});
                        mp[s]= len+1;
                        }
                    }
                }
                s[i]=c;
            }
        }
        for(auto it:mp){
            cout<<it.first<<" "<<it.second<<endl;
        }
        // here i get value of the depth 
        if(mp.find(endWord)!=mp.end()){
            vector<string> temp;
            temp.push_back(endWord);
            dfs(endWord, temp );
        }   
        return ans;
    }
};
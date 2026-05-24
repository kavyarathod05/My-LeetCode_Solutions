class Solution {
public:
    bool oneDiff(string a, string b){
        int n = a.size();
        int cnt= 0;
        for(int i=0;i<n;i++){
            if(a[i] != b[i]) {
                 cnt++;
            }
        }
        return cnt==1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        queue<pair<string, int>> q;
        vector<int> vis(n,0);
        q.push({beginWord, 1});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string word = it.first;
            int distance = it.second;
            if(word == endWord) return distance;

            for(int i=0;i<n;i++){
                if(!vis[i] && oneDiff(word, wordList[i])){
                    q.push({
                        wordList[i],
                        distance+1
                    });
                    vis[i]=1;
                }
            }
        }
        return 0; 
    }
};
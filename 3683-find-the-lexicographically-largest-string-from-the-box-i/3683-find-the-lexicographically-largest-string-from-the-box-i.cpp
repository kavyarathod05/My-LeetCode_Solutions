class Solution {
public:
    string answerString(string word, int n) {
        if(n==1) return word;
        int m = word.size();
        vector<int> v;
        char ch = *max_element(word.begin(), word.end());
        int maxi = m-n+1;
        int j=0;
        string maxa="";
        for(int i=0;i<m;i++){
            if(word[i]==ch) v.push_back(i);
        }
        for(int i:v){
            string ans= (maxi<=m-i)? word.substr(i,maxi):word.substr(i);
            maxa= max(ans, maxa);
        }
        return maxa;
    }
};
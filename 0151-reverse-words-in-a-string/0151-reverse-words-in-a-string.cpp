class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string>st;
        int i=0;
        while(i<n && s[i]==' ') i++;
        string curr = "";
        while(i<n){
            if(s[i] !=' '){
                curr+=s[i];
            }
            else{
                if(curr.empty()) {
                    i++;
                    continue;
                }
                st.push(curr);
                curr = "";
            }
            i++;
        }
        if(!curr.empty()) st.push(curr);
        string ans = "";
        while(!st.empty()){
            string top = st.top();
            st.pop();
            ans += top;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
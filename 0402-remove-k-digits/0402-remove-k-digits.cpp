class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0;i<num.size();i++){
            char c =num[i];
            while(!st.empty() && st.top() > c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i=0;
        while(i<res.size() && res[i]=='0'){
            i++;
        }
       return (i == res.size()) ? "0" : res.substr(i);

    }
};
class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(ans>=0) ans++;
                else{
                    cnt+= abs(ans);  
                    ans=1;
                    continue;
                }
            }
            else{
                ans--;
            }
        }
        cnt += abs(ans);
        return cnt;
    }
};
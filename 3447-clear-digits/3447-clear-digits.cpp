class Solution {
public:
    string clearDigits(string s) {
        int n =s.size();
        vector<bool> vis(n,false);
        
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9' && i>0){
                for(int j=i-1;j>=0;j--){
                    if(s[j]>='a' && s[j]<='z' && !vis[j]){
                        vis[j]=true;
                        break;
                    }
                }
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
            continue;
            }
            else{
                if(!vis[i]){
                    ans+=s[i];
                }
            }
        }
        return ans;
    }
};
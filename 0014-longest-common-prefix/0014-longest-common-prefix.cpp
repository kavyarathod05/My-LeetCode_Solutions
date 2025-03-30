class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n =strs.size();
        if(n==1){
            return strs[0];
        }
        string ans="";
        bool same= false;
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            for(int j=0;j<n;j++){
                if(strs[j][i]==c){
                    same= true;
                }
                else{
                    same= false;
                    break;
                }
            }
            if(same){
                ans+=c;
                same=false;
            }else{
                break;
            }
        }
        return ans;
    }
};
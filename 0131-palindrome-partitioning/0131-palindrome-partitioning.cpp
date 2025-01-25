class Solution {
public:
    void func(string s , int ind, vector<string>&path, vector<vector<string>>&ans){
        int n = s.size();
        if(ind==n){
            ans.push_back(path);
        }
        else{
            for(int i=ind;i<n;i++){
                if(isPalindrome(s, ind, i)){
                    path.push_back(s.substr(ind, i-ind+1));
                    func(s, i+1 , path , ans);
                    path.pop_back();
                }
            }
        }
    }
    bool isPalindrome(string s, int start , int end){
        while(start<end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        func(s,0,path, ans);
        return ans;
    }
};
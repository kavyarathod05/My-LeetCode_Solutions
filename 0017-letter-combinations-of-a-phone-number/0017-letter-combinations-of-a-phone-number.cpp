class Solution {
    map<int, string> m;
    vector<string> ans;
public:
    void makeCombinations(string &curr, string digits,int ind ){
        int n = digits.size();
        if(ind==n){
            ans.push_back(curr);
            return;
        }

        for(auto letter: m[digits[ind]-'0']){
            curr.push_back(letter);
            makeCombinations(curr, digits, ind+1);
            curr.pop_back();
        }
        return;
    }
   vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0) return ans;
        m[2] = "abc";
        m[3] = "def";
        m[4] = "ghi";
        m[5] = "jkl";
        m[6] = "mno";
        m[7] = "pqrs";
        m[8] = "tuv";
        m[9] = "wxyz";
        string currString = "";
        makeCombinations(currString , digits, 0);

        return ans;
    } 
};
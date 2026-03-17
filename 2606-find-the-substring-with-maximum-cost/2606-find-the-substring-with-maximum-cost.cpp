class Solution {
public:
    int find(char c, unordered_map<char, int>&mp){
        if(mp.find(c)!= mp.end()) return mp[c];
        else{
            return c-'a'+1;
        }
    }
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<chars.size();i++){
            mp[chars[i]]= vals[i];
        }
        int curr = 0;
        int maxi =0;
        if(mp.find(s[0])!= mp.end()){
            curr = mp[s[0]];
            maxi = curr;
        }
        else{
            curr = s[0]-'a'+1;
            maxi = curr;
        }
        for(int i=1;i<n;i++){
            curr = max(curr+find(s[i],mp), find(s[i],mp));
            maxi = max(maxi , curr);
        }
        return max(maxi , 0);
    }
};
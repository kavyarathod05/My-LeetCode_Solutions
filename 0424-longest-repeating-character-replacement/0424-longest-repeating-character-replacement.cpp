class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> mp;
        int maxlen=0;
        int maxfreq=0;
        int l=0,r=0;
        while(r<n){
            mp[s[r]]++;
            maxfreq= max(maxfreq, mp[s[r]]);
            int changes= (r-l+1)- maxfreq;
            if(changes<=k){
                maxlen= max(maxlen, (r-l+1));
            }
            else{
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return maxlen;
    }
};
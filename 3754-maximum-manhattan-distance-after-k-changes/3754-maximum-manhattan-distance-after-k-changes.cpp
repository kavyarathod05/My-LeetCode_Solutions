class Solution {
public:
    int maxDistance(string s, int k) {
        int n =s.size();
        unordered_map<char, int> mp;
         int vertical=0;
         int horizontal =0;
        int ans=0;
        int temp=0;
        for(int i=0; i<n;i++){
            mp[s[i]]++;
        vertical= abs(mp['S']- mp['N']);
        horizontal = abs(mp['E']- mp['W']);
        temp= min(i+1,vertical+horizontal+2*k);
        ans= max(ans, temp);
        }
        return ans;
        
    }
};
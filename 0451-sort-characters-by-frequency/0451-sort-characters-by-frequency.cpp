class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(auto it:s){
            mp[it]++;
        }
        vector<pair<int,char>>v;
        for(auto it:mp){
            v.push_back({it.second, it.first});
        }
        sort(v.rbegin(), v.rend());
        string ans = "";
        for(auto it:v){
            int cnt = it.first;
            char c = it.second;
            while(cnt--){
                ans += c;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> parent, size;
    int findParent(int x){
        if(parent[x]==x) return x;
        return findParent(parent[x]);
    }
    void Union(int u, int v){
        int up= findParent(u);
        int vp= findParent(v);
        if(up==vp) return;
        if(size[up]>size[vp]){
            size[up] += size[vp];
            parent[vp]=up;
        }
        else{
            size[vp] += size[up];
            parent[vp]= up;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();
        int m= baseStr.size();
        parent.resize(26);
        size.resize(26,1);
        for(int i=0;i<26;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            int c1= s1[i]-'a';
            int c2= s2[i]-'a';
            Union(c1,c2);
        }
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        for(int i=0;i<26;i++){
            int p = findParent(i);
            mp[p].push(i);
        }
        string ans;
        for(auto c:baseStr){
            int x= findParent(c-'a');
            ans.push_back(mp[x].top()+'a');
        }
        return ans;
    }
};
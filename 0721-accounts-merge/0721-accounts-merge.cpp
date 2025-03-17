class Solution {
public:
    int find(int node, vector<int>& par){
        if(par[node]==node) return node;
        return par[node]=find(par[node], par);
    }
    bool unionset(int u, int v, vector<int>& par, vector<int>& sz){
        int pu = find(u, par);
        int pv = find(v, par);
        if(pu==pv) return false;
        if(sz[pu]<sz[pv]){
            par[pu]=pv;
            sz[pv]+=sz[pu];
        }else{
            par[pv]=pu;
            sz[pu]+=sz[pv];
        }
        return true;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        map<string, int> mailtonode;
        vector<int> par(n);
        iota(par.begin(), par.end(), 0);
        vector<int> sz(n, 0);
        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){
                if(mailtonode.find(accounts[i][j])==mailtonode.end()) mailtonode[accounts[i][j]]=i;
                else unionset(i, mailtonode[accounts[i][j]], par, sz);
            }
        }
        map<int, vector<string>> nodemails;
        for(auto m:mailtonode){
            int p=find(m.second, par);
            nodemails[p].push_back(m.first);
        }
        vector<vector<string>> ans;
        for(auto nm:nodemails){
            vector<string> v;
            string name = accounts[nm.first][0];
            v.push_back(name);
            for(auto e:nm.second){
                v.push_back(e);
            }
            sort(v.begin()+1, v.end());
            ans.push_back(v);
        }
        return ans;
    }
};
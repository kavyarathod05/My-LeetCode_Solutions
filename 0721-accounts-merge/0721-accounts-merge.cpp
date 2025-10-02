class Solution {
public:
    int find(int node, vector<int>& par) {
        if(par[node] == node) return node;
        return par[node] = find(par[node], par);
    }

    bool unionset(int u, int v, vector<int>& par, vector<int>& sz) {
        int pu = find(u, par);
        int pv = find(v, par);
        if(pu == pv) return false;
        if(sz[pu] < sz[pv]) {
            par[pu] = pv;
            sz[pv] += sz[pu];
        } else {
            par[pv] = pu;
            sz[pu] += sz[pv];
        }
        return true;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string, int> mailtonode;
        vector<int> parent(n);
        vector<int> size(n, 1);
        iota(parent.begin(), parent.end(), 0);

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(mailtonode.find(email) == mailtonode.end()) {
                    mailtonode[email] = i;
                } else {
                    unionset(i, mailtonode[email], parent, size);
                }
            }
        }

        map<int, vector<string>> nodemails;
        for(auto& it : mailtonode) {
            string email = it.first;
            int node = it.second;
            int root = find(node, parent);
            nodemails[root].push_back(email);
        }

        vector<vector<string>> ans;
        for(auto& it : nodemails) {
            int node = it.first;
            vector<string> emails = it.second;
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), accounts[node][0]); // name at front
            ans.push_back(emails);
        }

        return ans;
    }
};

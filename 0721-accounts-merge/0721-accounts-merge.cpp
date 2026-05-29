class Solution {
public:
    void dfs(int node, vector<int> &comp , vector<int>&vis, vector<vector<int>>&adj){
        vis[node] =1;
        comp.push_back(node);
        for(auto nbr : adj[node]){
            if(!vis[nbr]){
                dfs(nbr, comp , vis, adj);
            }
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToAccount;
        int n = accounts.size();

        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j = 1; j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(emailToAccount.find(mail) == emailToAccount.end()){
                    emailToAccount[mail] = i;
                }
                else{
                    int prev = emailToAccount[mail];
                    adj[prev].push_back(i);
                    adj[i].push_back(prev);
                }
            }
        }   
        vector<int> vis(n,0);
        vector<vector<string>> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vector<int> comp;
                dfs(i, comp, vis ,adj);
                set<string> mails;
                for(auto acc : comp){
                    for(int i=1 ; i< accounts[acc].size();i++){
                        mails.insert(accounts[acc][i]);
                    }
                }
                vector<string> merged;
                merged.push_back(accounts[comp[0]][0]);
                for(auto it:mails){
                    merged.push_back(it);
                }
                ans.push_back(merged);
            }
        }
        return ans;
    }
};
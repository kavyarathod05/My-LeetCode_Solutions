class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis){
        vis[node] = 1;
        for(auto nbr: adj[node]){
            if(!vis[nbr]){
                dfs(nbr, adj , vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int total= connections.size();
        if(total < n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]) {
                cnt++;
                dfs(i, adj , vis);
            }
        }
        return cnt-1;
    }
};
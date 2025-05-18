class Solution {
public:
    void dfs(int node, vector<bool>&vis , vector<vector<int>>&adj){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, vis,adj);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        int len = connections.size();
        if(len<n-1) return -1;
        vector<vector<int>> adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,vis,adj);
            }
        }
        return c-1;

    }
};
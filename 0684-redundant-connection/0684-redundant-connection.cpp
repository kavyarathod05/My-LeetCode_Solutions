class Solution {
public:
    bool dfs(int src, int parent, vector<vector<int>>& adj, vector<bool>& vis) {
        vis[src] = true;
        for (int node : adj[src]) {
            if (!vis[node]) {  
                if (dfs(node, src, adj, vis)) return true;
            }
            else if (node != parent) {
                return true;  
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            vector<bool> vis(n + 1, false);
            if (dfs(u, -1, adj, vis)) {
                return edge;  
            }

        }

        return {};  
    }
};

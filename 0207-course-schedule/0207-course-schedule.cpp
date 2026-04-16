class Solution {
public:
    bool f(int ind, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathvis) {
        vis[ind] = 1;
        pathvis[ind] = 1;

        for (auto it : adj[ind]) {
            if (!vis[it]) {
                if (f(it, adj, vis, pathvis)) return true;
            }
            else if (pathvis[it]) {
                return true;
            }
        }

        pathvis[ind] = 0; 
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);

        for (auto it : p) {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0), pathvis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (f(i, adj, vis, pathvis)) return false;
            }
        }

        return true;
    }
};
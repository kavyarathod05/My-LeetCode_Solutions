class Solution {
public:
    bool dfs(int ind, vector<int>& vis, vector<int>& pathvis, vector<vector<int>>& adj){
        vis[ind] = 1;
        pathvis[ind] = 1;

        for(auto it : adj[ind]){
            if(!vis[it]){
                if(!dfs(it, vis, pathvis, adj))
                    return false;
            }
            else if(pathvis[it]){
                return false; // cycle detected
            }
        }

        pathvis[ind] = 0; // backtrack
        return true;
    }

    bool canFinish(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);       
        vector<int> pathvis(n, 0);
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(!dfs(i, vis, pathvis, adj))
                    return false;
            }
        }

        return true;
    }
};
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;      
        pathVis[node] = 1;   
        
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, adj, vis, pathVis)) return true;  
            } else if (pathVis[neighbor]) {
                return true;  
                }
        }
        
        pathVis[node] = 0; 
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
       
        for (auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]);  
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);  
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return false; 
            }
        }
        
        return true; 
        }
};

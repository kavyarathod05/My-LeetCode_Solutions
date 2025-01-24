class Solution {
public:
    bool dfs(int node, vector<int>& vis, vector<int>& inStack, vector<vector<int>>& graph) {
        vis[node] = 1;
        inStack[node] = 1;

        for (auto neighbor : graph[node]) {
            if (!vis[neighbor]) {
                if (dfs(neighbor, vis, inStack, graph)) {
                    return true;
                }
            } else if (inStack[neighbor]) {
                return true;
            }
        }

        inStack[node] = 0;
        vis[node] = 2;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> inStack(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, vis, inStack, graph);
            }
        }

        for (int i = 0; i < n; i++) {
            if (vis[i] == 2) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

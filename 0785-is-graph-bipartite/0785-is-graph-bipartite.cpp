class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] != -1)
                continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                int cl = color[node];
                for (auto neigh : graph[node]) {
                    if (color[neigh] == cl)
                        return false;
                    if (color[neigh] == -1) {
                        color[neigh] = !cl;
                        q.push(neigh);
                    }
                }
            }
        }
        return true;
    }
};
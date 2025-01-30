
class Solution {
    vector<int> graph[505];
    bool isb;
    vector<int> color;
    vector<int> connected;

public:
    bool dfs(int node, int currcolor = 1) {
        color[node] = currcolor;
        connected.push_back(node);
        for (int &neighbour : graph[node]) {
            if (color[neighbour] == 0) {
                if (!dfs(neighbour, 3 - currcolor)) return false;
            }
            else if (color[neighbour] == currcolor) {
                return false;
            }
        }
        return true;
    }

    int bfs(int node, int n) {
        vector<int> dis(n + 1, -1);
        queue<int> q;
        q.push(node);
        dis[node] = 1;
        int maxi = 1;
        
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int &neighbor : graph[curr]) {
                if (dis[neighbor] == -1) {
                    dis[neighbor] = dis[curr] + 1;
                    q.push(neighbor);
                    maxi = max(maxi, dis[neighbor]);
                }
            }
        }
        return maxi;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        for (int i = 1; i <= n; i++) graph[i].clear();
        color.assign(n + 1, 0);

        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxConnected = 0;

        for (int i = 1; i <= n; i++) {
            if (color[i] == 0) {
                connected.clear();
                if (!dfs(i)) return -1;
                
                int maxdis = 0;
                for (auto &node : connected) {
                    maxdis = max(maxdis, bfs(node, n));
                }
                maxConnected += maxdis;
            }
        }        
        return maxConnected;
    }
};

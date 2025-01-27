#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, unordered_set<int>> mp;
        int qsize = queries.size();
        vector<bool> ans(qsize, false);

        for (auto& p : prerequisites) {
            mp[p[0]].insert(p[1]);
        }

        for (int start = 0; start < num; ++start) {
            unordered_set<int> visited;
            dfs(start, mp, visited);
            mp[start].insert(visited.begin(), visited.end());
        }

        for (int i = 0; i < qsize; ++i) {
            if (mp[queries[i][0]].count(queries[i][1])) {
                ans[i] = true;
            }
        }

        return ans;
    }

private:
    void dfs(int node, unordered_map<int, unordered_set<int>>& mp, unordered_set<int>& visited) {
        if (mp.find(node) == mp.end()) return;
        for (int neighbor : mp[node]) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                dfs(neighbor, mp, visited);
            }
        }
    }
};

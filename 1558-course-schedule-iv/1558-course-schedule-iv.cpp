class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj ,vector<int>&vis, set<pair<int,int>>&s, int start){
        vis[node]=true;
        if(start != -1){
            s.insert({start, node});
        }
        for(auto& nei : adj[node]){
            if(!vis[nei]){
                dfs(nei , adj , vis, s, start);
            }
        }
    }
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = prerequisites.size();
        int qsize= queries.size();
        vector<vector<int>> adj(num);
        for(const auto& i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        set<pair<int,int>> s;
        for(int i=0;i<num;i++){
            vector<int> vis(num,false);
            dfs( i , adj,vis, s,i);
        }
        vector<bool> ans(qsize,false);
        for(int i=0;i<qsize;i++){
            if(s.find({queries[i][0], queries[i][1]}) != s.end()  ){
                ans[i]=true;
            }
        }
        return ans;
        
    }
};
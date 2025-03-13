class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int>path;
        queue<vector<int>>q;
        q.push({0});
        vector<int>vis(n,0);
        while(!q.empty()){
            vector<int>top= q.front();
            q.pop();
            if(top.back()==n-1){
                ans.push_back(top);
                continue;
            }
            for(auto it:graph[top.back()]){
                if(!vis[it]){
                    top.push_back(it);
                    q.push(top);
                    top.pop_back();
                }
            }
        }
        return ans;
    }
};
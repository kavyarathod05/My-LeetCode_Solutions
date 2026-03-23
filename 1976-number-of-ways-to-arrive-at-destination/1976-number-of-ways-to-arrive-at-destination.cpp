class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<vector<pair<int,int>>> adj(n);

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<int> ways(n,0);
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<>
        > pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            long long dis= it.first;
            int node= it.second;
            if(dis>dist[node]) continue;
            for(auto edge: adj[node]){
                int next = edge.first;
                long long newDist = edge.second+ dis;
                if(newDist < dist[next] ){
                    dist[next] = newDist;
                    ways[next]=  ways[node];
                    pq.push({newDist, next});
                }
                else if(newDist==dist[next]){
                    ways[next]= (ways[next]+ways[node])%mod;
                }
            }
        }
        
        return ways[n-1];
    }
};
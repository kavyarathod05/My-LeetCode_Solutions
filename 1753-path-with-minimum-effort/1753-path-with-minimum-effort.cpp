class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m= heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>>mini(n,vector<int>(m,1e9));
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        pq.push({0,{0,0}});
        mini[0][0]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff= it.first;
            int dx= it.second.first;
            int dy = it.second.second;
            if(dx==n-1 && dy==m-1){
                return diff;
            }
            for(int i=0;i<4;i++){
                int newx= dx+dir[i].first;
                int newy = dy + dir[i].second;
                if(newx>=0 && newy>=0 && newx<n && newy<m){
                    int neweffort=max(abs(heights[dx][dy]-heights[newx][newy]),diff);
                    if(neweffort<mini[newx][newy]){
                        mini[newx][newy]=neweffort;
                        pq.push({neweffort,{newx,newy}});
                    }
                }
            }
        }
        return 0;
    }
};
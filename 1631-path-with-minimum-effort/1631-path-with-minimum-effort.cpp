class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n= heights.size();
        int m= heights[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<pair<int,int>> dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<vector<int>> mini(n, vector<int>(m, 1e9));
        mini[0][0]=0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it= pq.top();
            pq.pop();
            int dist= it.first;
            int x= it.second.first;
            int y= it.second.second;
            if(x==n-1 && y==m-1){
                return dist;
            }
            for(int i=0;i<4;i++){
                int nx= x+ dir[i].first;
                int ny= y + dir[i].second;
                if(nx>=0 && ny>=0 && nx<n && ny<m ){
                    int neww= max(dist,abs(heights[nx][ny] - heights[x][y]));
                    if(neww<mini[nx][ny]){
                        mini[nx][ny]=neww;
                        pq.push({neww,{nx,ny}});
                    }
                }
            }
        }
        return 0;
    }
};
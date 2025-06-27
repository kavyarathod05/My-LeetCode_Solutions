class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n  =mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>> res(m,vector<int>(n,-1));
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    res[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx= i+ dir[k].first;
                int ny = j+ dir[k].second;
                if(nx>=0 && ny>=0 && nx<m && ny<n && res[nx][ny]==-1){
                    res[nx][ny] = 1+ res[i][j];
                    q.push({nx,ny});
                }
            }
        }
        return res;
    }
};
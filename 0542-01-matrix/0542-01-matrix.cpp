class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});   
                } else {
                    mat[i][j] = INT_MAX;
                }
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();

            for(auto& d : dirs){
                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && ny >= 0 && nx < m && ny < n){
                    if(mat[nx][ny] > mat[x][y] + 1){  
                        mat[nx][ny] = mat[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return mat;
    }
};
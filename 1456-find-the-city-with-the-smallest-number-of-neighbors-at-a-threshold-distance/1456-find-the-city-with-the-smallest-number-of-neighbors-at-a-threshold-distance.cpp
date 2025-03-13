class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n,vector<int>(n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            auto it=edges[i];
            mat[it[0]][it[1]]=it[2];
            mat[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++){
            mat[i][i]=0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if(mat[i][k]!=INT_MAX && mat[k][j]!=INT_MAX){
                        mat[i][j]=min(mat[i][k]+mat[k][j],mat[i][j]);
                    }
                }
            }
        }
        int mini = INT_MAX;
        int best=-1;
        for(int i=0;i<n;i++){
            int reach=0;
            for(int j=0;j<n;j++){
                if(mat[i][j]<=distanceThreshold){
                    reach++;
                }
            }
            if(reach<=mini){
                mini=reach;
                best=i;
            }
        }
        return best;
    }
};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {

            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 1) {

                    int mini = INT_MAX;

                    for(int x = 0; x < m; x++) {

                        for(int y = 0; y < n; y++) {

                            if(mat[x][y] == 0) {
                                mini = min(mini,
                                           abs(i - x) + abs(j - y));
                            }
                        }
                    }

                    ans[i][j] = mini;
                }
            }
        }

        return ans;
    }
};
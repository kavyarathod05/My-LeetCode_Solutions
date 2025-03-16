class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) 
            return 0;

        vector<int>last(n,0);
        

        for (int i = 0; i < m; i++) {
            vector<int>temp(n,-1);
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1) {
                    temp[j] = 0;
                } 
                else if (i == 0 && j == 0) {
                    temp[j]=1;
                } 
                else {
                    int up = (i > 0) ? last[j] : 0;
                    int left = (j > 0) ? temp[j-1] : 0;
                    temp[j]=up+left;
                }
            }
            last=temp;
        }
        return last[n-1];
    }
};

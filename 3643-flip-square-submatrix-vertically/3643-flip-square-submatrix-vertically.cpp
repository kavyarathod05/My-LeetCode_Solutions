class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>temp(k);
        
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                temp[i-x].push_back(grid[i][j]);
            }
        }
        reverse(temp.begin(), temp.end());
        for(int i=x;i<x+k;i++){
            for(int j=y;j<y+k;j++){
                grid[i][j] = temp[i-x][j-y];
            }
        }
        return grid;
    }
};
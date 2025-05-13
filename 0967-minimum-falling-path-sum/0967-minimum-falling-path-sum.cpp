class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0), curr(n, 0);

        for (int j = 0; j < n; j++) {
            prev[j] = matrix[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + prev[j];
                int leftDiag = (j > 0) ? matrix[i][j] + prev[j - 1] : INT_MAX;
                int rightDiag = (j < n - 1) ? matrix[i][j] + prev[j + 1] : INT_MAX;
                
                curr[j] = min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        return *min_element(prev.begin(), prev.end());
    }
};
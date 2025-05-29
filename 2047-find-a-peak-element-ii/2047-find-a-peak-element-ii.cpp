class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = m - 1;

        while (low <= high) {
            int midcol = (low + high) / 2;
            int maxrow = 0;

            // Find the row with the maximum value in the current column
            for (int i = 0; i < n; i++) {
                if (mat[i][midcol] > mat[maxrow][midcol]) {
                    maxrow = i;
                }
            }

            int curr = mat[maxrow][midcol];
            int left = midcol == 0 ? -1 : mat[maxrow][midcol - 1];
            int right = midcol == m - 1 ? -1 : mat[maxrow][midcol + 1];

            // Check if the current element is a peak
            if (curr > left && curr > right) {
                return {maxrow, midcol}; // Return the indices of the peak element
            }
            else if (curr < left) {
                high = midcol - 1; // Search in the left half
            } else {
                low = midcol + 1; // Search in the right half
            }
        }

        return {-1, -1}; 
    }
};

class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board) {
        int n = board.size();

        // check same row (left side)
        for (int j = 0; j < col; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // check lower-left diagonal
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void f(int col, vector<vector<string>>& ans, vector<string>& temp, int n) {
        if (col == n) {
            ans.push_back(temp);
            return; // IMPORTANT
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, temp)) {
                temp[row][col] = 'Q';
                f(col + 1, ans, temp, n);
                temp[row][col] = '.'; 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.'));

        f(0, ans, temp, n);
        return ans;
    }
};

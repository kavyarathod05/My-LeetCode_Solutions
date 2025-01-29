class Solution {

public:
    bool isValid(int i, int j, vector<vector<char>>& board, char c) {
        for(int k = 0; k < 9; k++) {
            if(board[k][j] == c) return false; 
            if(board[i][k] == c) return false;  
            int boxRow = (i/3) * 3 + k/3;
            int boxCol = (j/3) * 3 + k%3;
            if(board[boxRow][boxCol] == c) return false; 
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        int n = board.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '.') {  
                    for(char c = '1'; c <= '9'; c++) {
                        if(isValid(i, j, board, c)) {
                            board[i][j] = c; 
                            if(solve(board)) return true; 
                            board[i][j] = '.'; 
                        }
                    }
                    return false;  
                }
            }
        }
        return true;  
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};

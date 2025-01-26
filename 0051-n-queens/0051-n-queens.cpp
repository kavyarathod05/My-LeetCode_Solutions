class Solution {
public:
    bool isSafe(int board[][10], int i, int j, int n) {
        for(int row = 0; row < i; row++) {
            if(board[row][j] == 1) return false;
        }

        int x = i, y = j;
        while(x >= 0 && y >= 0) {
            if(board[x][y] == 1) return false;
            x--;
            y--;
        }

        x = i, y = j;
        while(x >= 0 && y < n) {
            if(board[x][y] == 1) return false;
            x--;
            y++;
        }

        return true;
    }

    bool NQueen(int board[][10], int i, int n, vector<vector<string>>& v) {
        if(i == n) {
            vector<string> curr;
            for(int row = 0; row < n; row++) {
                string rowStr;
                for(int col = 0; col < n; col++) {
                    if(board[row][col] == 1) rowStr += 'Q';
                    else rowStr += '.';
                }
                curr.push_back(rowStr);
            }
            v.push_back(curr);
            return false;
        }

        for(int j = 0; j < n; j++) {
            if(isSafe(board, i, j, n)) {
                board[i][j] = 1;
                bool NextQueen = NQueen(board, i + 1, n, v);
                if(NextQueen == true) return true;
                board[i][j] = 0;
            }
        }
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        int board[10][10] = {0};
        vector<vector<string>> v;
        NQueen(board, 0, n, v);
        return v;
    }
};

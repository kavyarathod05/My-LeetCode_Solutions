class Solution {
public:
    bool isSafe(int n, int m, int i, int j ){
        return (i<n)&& (i>=0)&& (j>=0) &&(j<m);
    }
    bool backtrack(vector<vector<char>>&board, string word, int pos, int i, int j){
        if(word[pos]!= board[i][j]){
            return false;
        }
        if(pos== word.length()-1){
            return true;
        }
        board[i][j]= '#';
        if(isSafe(board.size(), board[0].size(), i+1,j)){
            if(backtrack(board, word, pos+1, i+1, j))
            return true;
        }
        if(isSafe(board.size(), board[0].size(), i,j+1)){
            if(backtrack(board, word, pos+1, i, j+1))
            return true;
        }
        if(isSafe(board.size(), board[0].size(), i-1,j)){
            if(backtrack(board, word, pos+1, i-1, j))
            return true;
        }
        if(isSafe(board.size(), board[0].size(), i,j-1)){
            if(backtrack(board, word, pos+1, i, j-1))
            return true;
        }
        board[i][j]= word[pos];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row= board.size();
        int col = board[0].size();
        int startX=-1;
        int startY=-1;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    if(backtrack(board, word, 0, i, j)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
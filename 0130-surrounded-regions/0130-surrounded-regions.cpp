class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}}; 
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis) {
        vis[i][j] = 1;
        for(auto [dx, dy] : dir) {
            int nx = i + dx;
            int ny = j + dy;
            if(nx >= 0 && ny >= 0 && nx < board.size() && ny < board[0].size() 
               && !vis[nx][ny] && board[nx][ny] == 'O') {
                dfs(nx, ny, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        
        for(int i = 0; i < m; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) dfs(i, 0, board, vis);
            if(board[i][n-1] == 'O' && !vis[i][n-1]) dfs(i, n-1, board, vis);
        }
        for(int j = 0; j < n; j++) {
            if(board[0][j] == 'O' && !vis[0][j]) dfs(0, j, board, vis);
            if(board[m-1][j] == 'O' && !vis[m-1][j]) dfs(m-1, j, board, vis);
        }

     
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'O' && !vis[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

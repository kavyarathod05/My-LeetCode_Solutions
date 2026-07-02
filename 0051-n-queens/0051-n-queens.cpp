class Solution {
public:
    bool isSafe(int row ,int col , vector<string>&curr){
        if(row<0 || col <0 || row>curr.size() || col> curr.size()) return false;
        int drow= row;
        int dcol = col;
        
        while(row>=0 && col>=0){
            if(curr[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        row= drow;
        col = dcol;

        while(col>=0){
            if(curr[row][col]=='Q') return false;
            col--;
        }
        row= drow;
        col = dcol;
        while(row<curr.size() && col>=0){
            if(curr[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;

    }
    void f(int col, vector<vector<string>>&ans ,vector<string>&curr, int n){
        if(col==n){
            ans.push_back(curr);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row , col , curr)){
                curr[row][col]='Q';
                f(col+1 ,ans, curr, n);
                curr[row][col]='.';
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            curr[i]=s;
        }
        f(0,  ans, curr, n);
        return ans;
    }
};
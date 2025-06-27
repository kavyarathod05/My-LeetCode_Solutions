class Solution {
public:
    vector<int> nrow={0,0,-1,1};
    vector<int> ncol= {-1,1,0,0};
   
    int orangesRotting(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        vector<vector<int>> vis = grid;
        queue<pair<int, int>> q;
        int cntfresh=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==2){
                    q.push({i,j});
                }
                else if(vis[i][j]==1){
                    cntfresh++;
                }
            }
        }

        if(cntfresh==0){
            return 0;
        }
        if(q.empty()){
            return -1;
        }
        int mini=-1;
        while(!q.empty()){
            int size= q.size();
            while(size--){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int nr= x+ nrow[k];
                    int nc = y+ncol[k];
                    if(nr>=0 && nr< row && nc>=0 && nc<col && vis[nr][nc]==1){
                        vis[nr][nc]=2;
                        cntfresh--;
                        q.push({nr,nc});
                    }
                }
            }
            mini++;
        }
        if(cntfresh==0){
            return mini;
        }
        return -1;
       
    }
};
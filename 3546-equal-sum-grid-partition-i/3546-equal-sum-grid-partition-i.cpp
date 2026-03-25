class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> ph(m,0);
        vector<long long> pv(n,0);

        for(int i=0;i<m;i++){
            long long val = 0;
            for(int j=0;j<n;j++){
                val += grid[i][j];
            }
            ph[i] = val + (i>0 ? ph[i-1] : 0);
        }

        for(int i=0;i<n;i++){
            long long val = 0;
            for(int j=0;j<m;j++){
                val += grid[j][i];
            }
            pv[i] = val + (i>0 ? pv[i-1] : 0);
        }

        long long total = ph[m-1];

        if(total % 2 != 0) return false;

        for(int i=0;i<m;i++){
            if(ph[i] == total/2) return true;
        }

        for(int i=0;i<n;i++){
            if(pv[i] == total/2) return true;
        }

        return false;
    }
};
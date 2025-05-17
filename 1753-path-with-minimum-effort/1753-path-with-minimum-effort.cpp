class Solution {
public:
    int n,m;
    int minimumEffortPath(vector<vector<int>>& arr) {
         n = arr.size(); m = arr[0].size();
         
         int ans = INT_MAX;
         int start = 0;
         int end   = INT_MAX;
         while(start <= end){
            int mid = ((0LL + start + end)/(1LL * 2));
            if(fun(mid,arr) == true){
                ans = mid;
                end = mid - 1;
            }
            else {
                 start = mid+1;
            }
         }
         return ans;
    }
    bool isValid(int row,  int col){
        if(row >= 0 and row < n and col >=0 and col < m) return true;
        return false;
    }
    bool fun(int &mid, vector<vector<int>>&arr){
         vector<int>temp;
         vector<vector<bool>>vis(arr.size(),vector<bool>(arr[0].size(),false));
         queue<vector<int>>q;
         q.push({0,0,arr[0][0]});
         vis[0][0] = true;

         while(!q.empty()){
             temp = q.front();
             q.pop();

             int row = temp[0];
             int col = temp[1];
             int val = temp[2];

             if(row == arr.size()-1 and col == arr[0].size()-1) return true;

             if(isValid(row-1,col) == true and vis[row-1][col] == false and (abs(0LL + arr[row][col] - arr[row-1][col]) <= mid)){
                q.push({row-1,col,arr[row-1][col]});
                vis[row-1][col] = true;
             }
             if(isValid(row,col+1) == true and vis[row][col+1] == false and (abs(0LL + arr[row][col] - arr[row][col+1]) <= mid)){
                q.push({row,col+1,arr[row][col+1]});
                vis[row][col+1] = true;
             }
             if(isValid(row+1,col) == true and vis[row+1][col] == false and (abs(0LL + arr[row][col] - arr[row+1][col]) <= mid)){
                q.push({row+1,col,arr[row+1][col]});
                vis[row+1][col] = true;
             }
             if(isValid(row,col-1) == true and vis[row][col-1] == false and (abs(0LL + arr[row][col] - arr[row][col-1]) <= mid)){
                q.push({row,col-1,arr[row][col-1]});
                vis[row][col-1] = true;
             }
         }
         return false;
    }
};
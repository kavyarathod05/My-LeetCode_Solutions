#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int rows = matrix.size();
        int cols= matrix[0].size();
        if(matrix.empty() || matrix[0].empty()){
            return ans;
        }
        int left=0, right= cols-1 , top=0 , bottom= rows-1;
        while(left<= right && top<=bottom){
            for(int i= left;i<=right; i++){
                ans.pb(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++ ){
                ans.pb(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
            for(int i= right ; i>= left;i--){
                ans.pb(matrix[bottom][i]);
            }
            bottom--;
            }
            if(left<=right){
                for(int i= bottom;i>=top;i--){
                    ans.pb(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
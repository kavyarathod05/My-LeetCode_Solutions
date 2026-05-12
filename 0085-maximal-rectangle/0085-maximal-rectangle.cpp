class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> grid(m, vector<int>(n,0));
        int ans = 0;

        for(int j = 0; j < n; j++){
            if(matrix[0][j] == '1') grid[0][j] = 1;
        }

        for(int i = 0; i < m; i++){
            
            if(i > 0){
                for(int j = 0; j < n; j++){
                    if(matrix[i][j] == '1'){
                        grid[i][j] = grid[i-1][j] + 1;
                    } else {
                        grid[i][j] = 0;
                    }
                }
            }

            stack<int> st;
            for(int j = 0; j <= n; j++){
                int h = (j == n ? 0 : grid[i][j]);

                while(!st.empty() && grid[i][st.top()] > h){
                    int height = grid[i][st.top()];
                    st.pop();

                    int width = st.empty() ? j : j - st.top() - 1;
                    ans = max(ans, height * width);
                }
                st.push(j);
            }
        }
        return ans;
    }
};
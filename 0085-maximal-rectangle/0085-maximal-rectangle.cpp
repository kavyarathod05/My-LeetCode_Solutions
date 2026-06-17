class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> height(n, 0);
        int ans = 0;

        for(int i = 0; i < m; i++) {

            // Build histogram
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            stack<int> st;
            for(int j=0; j<=n;j++){
                while(!st.empty() && (j==n || height[st.top()] >= height[j])){
                    int heigh = height[st.top()];
                    st.pop();
                    int nsl = st.empty()?-1:st.top();
                    int nsr = j;
                    int width = nsr-nsl-1;
                    ans = max(ans, width*heigh);
                }
                st.push(j);
            }
        }

        return ans;
    }
};
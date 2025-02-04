class Solution {
public:
    vector<int> Nse(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            ans[i]= st.empty()?n:st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> Pse(vector<int>& heights){
        int n = heights.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            ans[i]= st.empty()?-1:st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse= Nse(heights);
        vector<int> pse= Pse(heights);
        int maxi= 0;
        for(int i=0;i<n;i++){
            int area= ((nse[i])-(pse[i])-1)*heights[i];
            maxi= max(area, maxi);
        }
        return maxi;
    }
};
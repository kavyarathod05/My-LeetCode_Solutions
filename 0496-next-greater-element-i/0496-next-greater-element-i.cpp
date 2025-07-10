class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> ans(n,-1);
        vector<int> temp(m);
        temp[m-1]=-1;
        stack<int>st;
        st.push(nums2[m-1]);
        for(int i=m-2;i>=0;i--){
            if(st.top()>nums2[i]){
                temp[i]=st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<nums2[i]){
                    st.pop();
                }
                if(st.empty()){
                    temp[i]=-1;
                    st.push(nums2[i]);
                }
                else{
                    temp[i]=st.top();
                    st.push(nums2[i]);
                }
            }
        }
        unordered_map<int,int> mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]]=i;
        }
        for(int i=0;i<n;i++){
             ans[i]= temp[mp[nums1[i]]];
        }
        return ans;
    }
};
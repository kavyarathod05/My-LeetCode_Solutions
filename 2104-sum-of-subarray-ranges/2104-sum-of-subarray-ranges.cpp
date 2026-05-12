class Solution {
public:
vector<int>getlmin(vector<int>&nums,int n)
{
    vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        ans[i]= st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}

vector<int>getlmax(vector<int>&nums,int n)
{
  vector<int> ans(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        while(!st.empty() && nums[st.top()]<nums[i]) st.pop();
        ans[i]= st.empty()?-1:st.top();
        st.push(i);
    }
    return ans;
}
vector<int>getrmin(vector<int>&nums,int n)
{
  vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]>=nums[i]) st.pop();
        ans[i]= st.empty()?n :st.top();
        st.push(i);
    }
    return ans;
}
vector<int>getrmax(vector<int>&nums,int n)
{
  vector<int> ans(n);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[st.top()]<=nums[i]) st.pop();
        ans[i]= st.empty()?n:st.top();
        st.push(i);
    }
    return ans;
}

    long long subArrayRanges(vector<int>& nums) {
        long long mini=0;
        long long maxi=0;
        int n=nums.size();
        vector<int>lmin=getlmin(nums,n);
        vector<int>lmax=getlmax(nums,n);
        vector<int>rmin=getrmin(nums,n);
        vector<int>rmax=getrmax(nums,n);

        for(int i=0;i<n;i++)
        {
            int a=i-lmin[i];
            int b=i-lmax[i];
            int c=rmin[i]-i;
            int d=rmax[i]-i;

            mini+=1LL* a*c*nums[i];
            maxi+=1LL* b*d*nums[i];
            
        }
        return maxi-mini;
    }
};
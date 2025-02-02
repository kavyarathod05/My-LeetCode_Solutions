class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& s, vector<int>& e) {
        int n=s.size();
        vector<int> gap;
        gap.push_back(s[0]);
        for(int i=1;i<n;i++){
            gap.push_back(s[i]-e[i-1]);
        }
        gap.push_back(eventTime-e[n-1]);
        vector<int> left(n+1,0),right(n+1,0);
        for(int i=1;i<gap.size();i++){
            left[i]=max(left[i-1],gap[i-1]);
        }
        for(int j=gap.size()-1;j>=1;j--){
            right[j-1]=max(right[j],gap[j]);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int first=0;
            if(left[i]>=(e[i]-s[i])){
                first=gap[i]+gap[i+1]+e[i]-s[i];
            }
            int second=0;
            if(right[i+1]>=(e[i]-s[i])){
                second=gap[i]+gap[i+1]+(e[i]-s[i]);
            }
            int third=gap[i]+gap[i+1];
            maxi=max(maxi,max(first,max(second,third)));
        }
        return maxi;
    }
};
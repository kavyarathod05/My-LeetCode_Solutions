class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps;
        if(startTime[0] != 0)  gaps.push_back(startTime[0]);
        for (int i = 1; i < n; i++) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }
        if(endTime[n-1] != eventTime)  gaps.push_back(eventTime - endTime[n - 1]);
        int sum=0;
        if(k+1> gaps.size()) k= gaps.size()-1;
        for(int i=0;i<k+1;i++){
            sum+= gaps[i];
        }
        int l=0;
        int r=k+1;
        int maxi = sum;
        while(r< gaps.size()){
            sum+= gaps[r];
            r++;
            sum-= gaps[l];
            l++;
            maxi= max(maxi, sum);            
        }
       
        return maxi;
    }
};

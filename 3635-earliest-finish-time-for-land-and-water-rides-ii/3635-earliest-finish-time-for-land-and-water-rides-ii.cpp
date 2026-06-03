class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int ans = INT_MAX;
        int mini  = INT_MAX;
        for(int i=0;i<n;i++){
            mini = min(mini, landStartTime[i]+landDuration[i]);
        }
        for(int j=0;j<m;j++){
            int val = max(mini, waterStartTime[j]) + waterDuration[j];
            ans = min(ans, val);
        }
        mini  = INT_MAX;
        for(int i=0;i<m;i++){
            mini = min(mini, waterStartTime[i]+waterDuration[i]);
        }
        for(int j=0;j<n;j++){
            int val = max(mini, landStartTime[j]) + landDuration[j];
            ans = min(ans, val);
        }
        return ans;
    }
};
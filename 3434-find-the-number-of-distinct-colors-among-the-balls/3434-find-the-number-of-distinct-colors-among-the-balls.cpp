class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> ball, colour;
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto q = queries[i];
            if(ball.find(q[0]) != ball.end() ){
               int oldColour= ball[q[0]];
               colour[oldColour]--;
                if(colour[oldColour]==0){
                    colour.erase(oldColour);
                }
            }
            ball[q[0]]=q[1];
            colour[q[1]]+=1;
            ans.push_back(colour.size());
        }
        return ans;
    }
};
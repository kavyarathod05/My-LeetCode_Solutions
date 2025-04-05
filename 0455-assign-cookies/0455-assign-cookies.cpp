class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ng= g.size();
        int ns= s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i=0,j=0;
        while(i<ng && j<ns){
            if(g[i]<=s[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return i;
    }
};
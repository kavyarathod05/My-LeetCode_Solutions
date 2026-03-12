class Solution {
public:
    string s;
    long long dp[10][2][2][1024];
    int f(int pos, int tight , int started , int mask){
        if(pos == s.size()){
            return started;
        }
        if(dp[pos][tight][started][mask]!=-1) return dp[pos][tight][started][mask];
        int limit = tight ? (s[pos]-'0'):9;
        int ans=0;
        for(int d=0;d<=limit; d++){
            int newTight = tight && (d==limit);
            //still leading zeros are coming
            if(!started){
                if(d==0){
                ans += f(pos+1, newTight , started, mask);
                }
                else{
                ans += f(pos+1, newTight , 1, mask|(1<<d));
                }
            }
            else{
                if(mask & (1<<d)) continue;
                else ans+=f(pos+1, newTight , started , mask|(1<<d));
            }
        }
        return dp[pos][tight][started][mask]= ans;
    }
    int numDupDigitsAtMostN(int n) {
        s = to_string(n);
        memset(dp ,-1, sizeof(dp));
        //pointer , value , size
        int diff = f(0,1,0,0);
        return n-diff;
    }
};